#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {

    cout << "Content-type:text/html\r\n\r\n";

    string data = getenv("CONTENT_LENGTH") ? getenv("CONTENT_LENGTH") : "";
    int len = stoi(data);

    string input;
    for (int i = 0; i < len; i++) {
        char ch = getchar();
        input += ch;
    }

    // Example input: user=admin&pass=123
    string user = input.substr(input.find("user=") + 5,
                 input.find("&") - (input.find("user=") + 5));

    string pass = input.substr(input.find("pass=") + 5);

    // LOGIN CHECK
    if (user == "admin" && pass == "123") {
        cout << "<html><head>";
        cout << "<title>Login Successful</title>";
        cout << "<link rel='stylesheet' href='/result.css'>";
        cout << "</head><body>";
        cout << "<main class='portal-card'>";
        cout << "<div class='badge'>OK</div>";
        cout << "<h2>Login Successful</h2>";
        cout << "<p class='subtitle'>Welcome to the verified supply chain dashboard.</p>";
        cout << "<a href='/index.html'>Go to Dashboard</a>";
        cout << "</main>";
        cout << "</body></html>";
    } else {
        cout << "<html><head>";
        cout << "<title>Invalid Login</title>";
        cout << "<link rel='stylesheet' href='/result.css'>";
        cout << "</head><body>";
        cout << "<main class='portal-card'>";
        cout << "<div class='badge'>!</div>";
        cout << "<h2>Invalid Login</h2>";
        cout << "<p class='subtitle'>Please check your credentials and try again.</p>";
        cout << "<a href='/login.html'>Try Again</a>";
        cout << "</main>";
        cout << "</body></html>";
    }

    return 0;
}
