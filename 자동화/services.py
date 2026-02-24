import os
from api.solved import get_problem_info
# from api.notion import create_page
from pathlib import Path

def make_file(problem_id,ext):
    info = get_problem_simple_info(problem_id=problem_id)
    target_path = Path.cwd() / f"{problem_id}_{info['tier']}_{info['title']}.{ext}"

    target_path.write_text("""#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
}""", encoding="utf-8")
    print(f"파일이 생성되었습니다: {target_path}")

    os.system(f'code "{target_path}"')

def level_to_tier(level):
    # 티어 이름 리스트
    tier_names = ["Bronze", "Silver", "Gold", "Platinum", "Diamond", "Ruby"]

    if 1 <= level <= 30:
        return f"{tier_names[(level-1)//5]}{5-(level-1)%5}"
    elif level == 31:
        return "Master"
    else:
        return "Unrated"

def get_problem_simple_info(problem_id):
    info = get_problem_info(problem_id)

    title = info.get('titleKo')
    level = info.get('level',0)
    tier = level_to_tier(level)
    tags = [ # tags = [한국어 태그 이름들]
        name_info['name'] 
        for tag in info['tags'] 
        for name_info in tag['displayNames'] 
        if name_info['language'] == 'ko'
    ]
    
    return {
        'title': title,
        'level': level,
        'tier': tier,
        'tags': tags
    }

# def upload(problem_id):
#     result = get_problem_simple_info(problem_id=problem_id)
#     create_page(problem_id=problem_id,title=result['title'],level=result['level'],tier=result['tier'],tags=result['tags'])

