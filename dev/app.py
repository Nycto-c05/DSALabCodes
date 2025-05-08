import streamlit as st
from langchain_google_genai import ChatGoogleGenerativeAI
from langchain.memory import ConversationBufferMemory
from langchain.chains import LLMChain
from langchain.prompts import PromptTemplate
import os
from dotenv import load_dotenv

# Load environment variables
load_dotenv()

def initialize_session_state():
    """Initialize session state variables"""
    if "memory" not in st.session_state:
        st.session_state.memory = ConversationBufferMemory(
            memory_key="history", 
            input_key="human_input",  # The key that will be saved to memory
            return_messages=True
        )
    
    if "conversation_started" not in st.session_state:
        st.session_state.conversation_started = False

def get_llm(api_key, model_name="gemini-2.0-flash", temperature=0.7):
    """Initialize and return the LLM"""
    return ChatGoogleGenerativeAI(
        model=model_name,
        temperature=temperature,
        google_api_key=api_key,
    )

def create_chain(llm, system_prompt):
    """Create LLMChain with the given LLM and system prompt"""
    # Create prompt template with system prompt embedded
    prompt_template = PromptTemplate(
        input_variables=["history", "human_input"],
        template=(
            f"{system_prompt}\n\n"
            "Conversation so far:\n{history}\n"
            "Human: {human_input}\n"
            "Assistant:"
        )
    )
    
    # Create chain
    return LLMChain(
        llm=llm,
        prompt=prompt_template,
        memory=st.session_state.memory,
        verbose=False
    )

def display_conversation_history():
    """Display the conversation history"""
    if st.session_state.memory:
        for msg in st.session_state.memory.chat_memory.messages:
            with st.chat_message(msg.type):
                st.markdown(msg.content)

def clear_conversation():
    """Clear the conversation history"""
    if st.session_state.memory:
        st.session_state.memory.clear()
    st.session_state.conversation_started = False
    st.rerun()

def main():
    # Configure the Streamlit page
    st.set_page_config(
        page_title="Gemini Flash Chatbot with Memory", 
        layout="wide",
        menu_items={
            'About': "A chatbot powered by Google's Gemini AI model and LangChain"
        }
    )
    
    # Initialize session state
    initialize_session_state()
    
    # Header
    st.title("⚡ Gemini-2.0-Flash Chatbot with Memory")
    st.markdown("*Powered by LangChain + Streamlit*")
    
    # Sidebar: System prompt and settings
    with st.sidebar:
        st.header("Configuration")
        
        # API key input
        api_key = os.getenv("GOOGLE_API_KEY", "")
        provided_api_key = st.text_input(
            "Google API Key", 
            value=api_key,
            type="password",
            placeholder="Enter your Google API key",
            help="Get your API key from https://makersuite.google.com/app/apikey"
        )
        
        # Model selection
        model_name = st.selectbox(
            "Model",
            options=["gemini-2.0-flash", "gemini-2.0-pro"],
            index=0,
            help="Select the Gemini model to use"
        )
        
        # Temperature setting
        temperature = st.slider(
            "Temperature",
            min_value=0.0,
            max_value=1.0,
            value=0.7,
            step=0.1,
            help="Higher values make the output more random, lower values make it more deterministic"
        )
        
        # System prompt
        st.header("System Prompt")
        system_prompt = st.text_area(
            "Define assistant behavior:", 
            value="You are a helpful AI assistant.", 
            height=150,
            help="This sets the personality and behavior of the assistant"
        )
        
        # Clear conversation button
        if st.session_state.conversation_started:
            if st.button("Clear Conversation", type="primary"):
                clear_conversation()
    
    # Main chat area
    chat_container = st.container()
    
    with chat_container:
        # Display conversation history
        display_conversation_history()
    
    # User input - must be outside any container to avoid StreamlitAPIException
    user_input = st.chat_input("Type your message...")
    
    if user_input:
        if not provided_api_key:
            st.error("Please enter your Google API key in the sidebar.")
            return
        
        # Add user message to display
        with st.chat_message("human"):
            st.markdown(user_input)
        
        # Set the conversation as started
        st.session_state.conversation_started = True
        
        # Show spinner while processing
        with st.spinner("Thinking..."):
            try:
                # Initialize LLM with the provided API key
                llm = get_llm(
                    api_key=provided_api_key,
                    model_name=model_name,
                    temperature=temperature
                )
                
                # Create and run the chain
                chain = create_chain(llm, system_prompt)
                response = chain.invoke(
                    {
                        "human_input": user_input
                    }
                )
                
                # Display AI response
                with st.chat_message("ai"):
                    st.markdown(response["text"])
                    
            except Exception as e:
                st.error(f"Error: {str(e)}")

if __name__ == "__main__":
    main()