import serial
import streamlit as st
import time
import pandas as pd
import plotly.express as px
import numpy as np
import plotly.graph_objects as go
from arduino_to_py import read
import openai
#client = openai.OpenAI()

import os
from io import StringIO
os.environ["OPENAI_API_KEY"] = 'your_key'
openai.api_key  = os.getenv("OPENAI_API_KEY")

'''
def react(df, model="gpt-3.5-turbo"): 
        prompt = f"""role':'assistant weather analyzer',
                'content':
                Get information from the following dataset ```{df}``` in an emergency caller\
                1. give one explanation of current weather condition based on the data given
                
                Output:
                save all the information in JSON format, with the key: name, type, location, symptoms\
                """
        messages = [{"role": "user", "content": prompt}]
        response = client.chat.completions.create(
            model=model,
            messages=messages,
            temperature=0,
        )
'''


def plot_graph(cur, time, placeholder, t, wl, ml, w, li):
    fig1 = go.Figure()
    if t: fig1.add_trace(go.Line(x=time, y=cur['Temperature'], name = 'Temperature'))
    if wl: fig1.add_trace(go.Line(x=time, y=cur['Water_Height'], name = 'Water_Height'))
    if ml: fig1.add_trace(go.Line(x=time, y=cur['Moisture_Level'], name = 'MyHill Moisture Level'))
    if w: fig1.add_trace(go.Line(x=time, y=cur['Wind'], name = 'Windberg Wind-Farm Current'))
    if li: fig1.add_trace(go.Line(x=time, y=cur['Light_In'], name = 'Light_In'))
    placeholder.write(fig1)

# fishmiller chemical river
# rofarts community

st.title('Bahen City of Information and Technology')
st.subheader('weather & energy source monitoring')
st.sidebar.subheader('mice_family_version - special thanks to EMMA!')

d = [{'Temperature':0, 'Water_Height': 0, 'Moisture_Level': 0, 'Wind': 0, 'Light_In':0}]
df = pd.DataFrame(d)
speed = 0.1
real_time = np.linspace(0, 60, 300)


st.subheader('Instant Monitor Graph')
options = df.columns
weather = st.multiselect('Which info would you like to see?', options, ['Temperature'])
t, wl, ml, w, li = 0, 0, 0, 0, 0
if 'Temperature' in weather: t = 1
if 'Water_Height' in weather: wl = 1
if 'Moisture_Level' in weather: ml = 1
if 'Wind' in weather: w = 1
if 'Light_In' in weather: li = 1
placeholder = st.empty()

if st.button("START!", key="1"):
    for i in range(300):
        cur = read()
        df = pd.concat([df, pd.DataFrame(cur)])
        plot_graph(df, real_time, placeholder, t, wl, ml, w, li)
        time.sleep(speed)
        #react(df)
        
        
    