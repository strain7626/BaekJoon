import requests

def get_problem_info(problem_id):
    # solved.ac API URL
    url = f"https://solved.ac/api/v3/problem/show?problemId={problem_id}"
    
    headers = {
        "Content-Type": "application/json",
        "User-Agent": "Mozilla/5.0"
    }

    response = requests.get(url, headers=headers)

    if response.status_code == 200:
        return response.json()
    else:
        return {"error": f"Error Code: {response.status_code}"}
    

# 출력부
# print(f"문제 제목: {info.get('titleKo')}")
# print(f"난이도: {level}")
# print(f"티어: {tier}")
# print(f"태그들: {tags}")