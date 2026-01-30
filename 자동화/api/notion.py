import os
from dotenv import load_dotenv
import requests
from datetime import datetime

load_dotenv()

NOTION_TOKEN = os.getenv("NOTION_TOKEN")
DATABASE_ID = os.getenv("DATABASE_ID")

headers = {
    "Authorization": "Bearer " + NOTION_TOKEN,
    "Content-Type": "application/json",
    "Notion-Version": "2022-06-28",
}

def create_page(problem_id,title,level,tier,tags):
    # 현재 날짜 가져오기 (예: 2026-01-28)
    current_date = datetime.now().date().isoformat()
    tier_icon_url = f"https://static.solved.ac/tier_small/{level}.svg"  

    # 1. 전송할 데이터 세팅
    data = {
        "parent": { "database_id": DATABASE_ID },
        "icon": {
            "type": "external",
            "external": {
                "url": tier_icon_url
            }
        },
        "properties": {
            "작성일": { "date": { "start": current_date } },
            "번호_티어_제목": { 
                "title": [
                    { "text": { "content": f"{problem_id}_{tier}_{title}" } }
                ]
            },
            "알고리즘": { "multi_select": [{ "name": tag, "color": "gray" } for tag in tags] },
            "URL": { "url": f"https://www.acmicpc.net/problem/{problem_id}" },
        }
    }

    # 2. API 요청 전송
    response = requests.post("https://api.notion.com/v1/pages", headers=headers, json=data)

    if response.status_code == 200:
        print("성공적으로 추가되었습니다!")
    else:
        print(f"오류 발생: {response.status_code}")
        print(response.text)