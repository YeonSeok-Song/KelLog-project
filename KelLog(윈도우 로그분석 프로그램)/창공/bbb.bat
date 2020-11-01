Auditpol /set /subcategory:"파일 시스템" /success:enable
Auditpol /set /subcategory:"프로세스 만들기" /success:enable
Auditpol /resourceSACL /set /type:File /user:everyone /success /access:FRFW