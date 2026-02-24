import sys
from services import make_file

if len(sys.argv) > 1:
    try:
        problem_id = int(sys.argv[1])
        make_file(problem_id=problem_id,ext='cpp')
    except ValueError:
        print("오류: 올바른 문제 번호를 입력해주세요.")
else:
    print("사용법: 백준 (문제번호)")