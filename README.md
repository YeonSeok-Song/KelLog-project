### KelLog-project
##윈도우 이벤트 로그 분석기

제안서

#1. 설계의 목표 

	가. 설계 주제
		“Kellogg” 설계는 로그 분석 프로그램으로 부팅, 파일이 실행될 때 발생하는 로그를 수집 후 차트와  타임라인을 제공한다.

	나. 설계 개요
		“Kellogg”는 GUI기반으로 설계하여 일반 사용자도 손쉽게 사용할 수 있는 로그분석 프로그램이다.
 		주 기능으로는 부팅로그, 파일실행로그, 해당파일의 로그를 수집, 검색하고 실행빈도 등을 연산하여 타임라인과 차트, 
		그래프 등의 직관적인 인터페이스를 통해 데이터를 사용자에게 제공한다.


#2. 기존 제품 분석(제품 개요, 기능 설명 및 분석)
	NTFS log Tracker : NTFS의 $LogFile, $UsnJrnl, $MFT 파일을 파싱하여 CSV파일포맷으로 결과를 출력하는 기능을 제공한다. 
	또한 SQLite DB파일을 열어 $Log File을 추출할 수 있다.

	고클린 : 컴퓨터 부팅 시간과 종료시간을 제공하며 파일 다운로드 기록과 블루스크린 시점과 이유를 나타내어 준다. 
	이외에 파일 삭제 , 인터넷 기록 삭제등의 기술을 지원한다.
	
		- 서비스관리 : 서비스 프로그램을 시작/중지 시키는 기능이다.
		-  시작프로그램 관리: 시작프로그램을 삭제해주는 기능이다.
		-  컴퓨터 사용시간 체크 : 컴퓨터의 켜진시간과 꺼진시간을 체크한다.
		-  블루스크린 정보 : 블루스크린이 발생한 시간과 추정 원인을 체크한다.

	Event viewer : 윈도우에서 기본으로 제공하는 프로그램으로 응용프로그램, 보안 ,시스템등 운영체제와 관련된 로그들을 확인 할 수 있다.
		
		- 이벤트 검색: 사용자가 원하는 이벤트를 검색하여 확인한다.

#3. 기능적 요구사항

	가. 파일 실행 로그수집기능
	
		  - 실행된 파일의 파일명, 용량, 실행된 시간과 날짜, 파일권한에 대한 로그를 수집한다.

	나. 수집된 파일로그의 다양한 출력기능
	
  		- 수집된 로그를 사용자가 설정한 차순 으로 출력한다.

			EX) 파일용량별 오름차순, 내림차순
    	    		    파일권한별 오름차순, 내림차순

  		- 파일이 실행된 순서 타임라인 출력기능
			사용자가 설정한 날짜 안에서 실행된 파일을 시간 순으로 출력한다.

				EX) A와 B파일 타임라인 표시
<img src="https://github.com/YeonSeok-Song/KelLog-project/blob/main/image/%ED%91%9C.PNG">

 		 - 파일의 실행 빈도, 실행 시간 등 그래프 출력
			사용자가 설정한 날짜 안에서 파일 실행 빈도, 실행 시간을 그래프로 출력한다.

				EX) A와 B파일 실행 빈도, 실행 시간 비교 표시
<img src="https://github.com/YeonSeok-Song/KelLog-project/blob/main/image/%EA%B7%B8%EB%9E%98%ED%94%84.PNG">
<img src="https://github.com/YeonSeok-Song/KelLog-project/blob/main/image/%EC%9D%BC%EB%B3%84%20%ED%8C%8C%EC%9D%BC%20%EC%82%AC%EC%9A%A9%EC%8B%9C%EA%B0%84.PNG">
<img src="https://github.com/YeonSeok-Song/KelLog-project/blob/main/image/%EC%9D%BC%EC%9E%90%20%EB%B2%94%EC%9C%84%20%EA%B2%80%EC%83%89.PNG">

	다. 수집된 파일로그 검색
  		파일이 실행된 날짜, 시간, 파일명, 권한으로 원하는 파일을 검색한다.

	라. 부팅로그 수집
  		시스템의 시작 및 정상적인 종료, 비정상적인 종료에 대한 로그를 수집한다.

	마. 수집된 부팅로그의 다양한 출력기능
	
  		- 수집된 부팅 로그를 유형별 분류하고 출력한다.
	
			EX) 시스템 시작 별 로그 출력
	    		    정상적인 종료 별 로그 출력
	                    비정상적인 종료 별 로그 출력

  		- 사용자가 설정한 날짜별 비정상적, 정상적인 종료 횟수와 비정상적인 종료를 타임라인 표시

  		- 비정상적인 종료의 원인을 횟수별로 그래프를 이용해 출력한다.

	바. 윈도우 로그 관리 및 수집 범위 설정
	
		 - 윈도우의 로그관리 및 감사정책 설정을 쉽게 접근할 수 있게 한다.

#4. 외부 인터페이스 요구사항
	가. 사용자 인터페이스
	
 		- 메인화면 구성
<img src="https://github.com/YeonSeok-Song/KelLog-project/blob/main/image/%EB%A9%94%EC%9D%B8%ED%99%94%EB%A9%B4.PNG">
		
		- 파일로그 검색
<img src="https://github.com/YeonSeok-Song/KelLog-project/blob/main/image/%ED%8C%8C%EC%9D%BC%20%EB%A1%9C%EA%B7%B8%20%EA%B2%80%EC%83%89.PNG">

		- 부팅로그 검색
<img src="https://github.com/YeonSeok-Song/KelLog-project/blob/main/image/%EB%B6%80%ED%8C%85%EB%A1%9C%EA%B7%B8.PNG">

		- 컴퓨터 사용시간 체크
<img src="https://github.com/YeonSeok-Song/KelLog-project/blob/main/image/%EC%BB%B4%ED%93%A8%ED%84%B0%20%EC%82%AC%EC%9A%A9%EC%8B%9C%EA%B0%84%20%EC%B2%B4%ED%81%AC.PNG">

#5. 기대효과(경제성, 사회성, 독창성 등)

	경제성 : 회사에서는 로그분석체계를 구축하는데 상당한 비용을 들인다. 방법으로는 여러 가지가 있는데, 대표적으로는

		1. 로그분석프로그램을 구매한다.
		2. 회사의 환경에 맞는 전용 로그프로그램을 만든다.
	
	기존 제품 분석에 사용된 로그분석 프로그램을 이용하는데 상당한 금액이 필요하다.
	
<img src="https://github.com/YeonSeok-Song/KelLog-project/blob/main/image/%EB%A1%9C%EA%B7%B8%20%EB%B6%84%EC%84%9D%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8%20%EC%A2%85%EB%A5%98.PNG">
			
	5만원부터 200만원까지 다양한 가격으로 판매되고 있다.
	우리 프로그램은 판매되고 있는 프로그램들의 기본기능을 무료로 제공하며 원한다면 사용자가 원하는 대로 수정할 수 있게 오픈소스를 제공한다.

	사회성 : 직관적이고 간단한 인터페이스를 통해 누구나 쉽게 자신의 로그를 확인할 수 있어 개인정보보호에 기여할 수 있고 오픈소스, 
		프리웨어로 누구나 무료로 사용할 수 있어 기초적인 로그 분석 교육에 활용할 수 있다.

	편의성 : 시중에 나와 있는 프로그램들과 비교했을 때, 크게 독창적이지는 않지만 여러 프로그램의 기능을 접목해 
		하나의 프로그램으로 여러 프로그램을 사용하는 효과를 낸다.

	보안성 : 실행된 파일의 로그와 부팅로그를 분석해 사용자가 원치 않았을 때 실행과 부팅을 나타내어 제공함으로써
		해킹의 위협을 예방하고 보안을 강화할 수 있다.

	
	
