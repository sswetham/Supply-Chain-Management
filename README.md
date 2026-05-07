STEP 0: Install Required Tools
vscode
mingw - https://sourceforge.net/projects/mingw/
xampp - https://www.apachefriends.org/

STEP 1: Open Project in VS Code

C: Chain-project
 ├── htdocs\
 │    ├── login.html  
 │    ├── index.html   (dashboard)
 │    ├── result.css
 │
 ├── cgi-bin\
 │    ├── login.cgi 
 │    ├── login.cpp  
 │    ├── supply.cpp 
 │    ├── supply.cgi
 │
 ├── orders.csv


Step 5. Compile Command (Terminal)
cd cgi-bin
g++ supply.cpp -o supply.cgi
g++ login.cpp -o login.cgi


Step 3.  Copy Files from the project folder to Xampp folder

Step 4. 
Start Apache → Open browser:
http://localhost/login.html

username : admin
password : 123
