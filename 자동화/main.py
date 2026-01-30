from services import upload, make_file

cmd, problem_id = input("""
다음의 명령어중 하나를 입력하세요.
 - upload (문제 번호) : Notion에 내 코드를 업로드합니다.
 - makecpp (문제 번호) : 현재 폴더에 '번호_티어_제목.cpp' 형식의 파일을 생성합니다. 

->""").split()

problem_id=int(problem_id)
    
if cmd=="upload":
    upload(problem_id)
elif cmd=="makecpp":
    make_file(problem_id,'cpp')

