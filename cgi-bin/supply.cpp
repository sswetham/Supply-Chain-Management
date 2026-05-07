#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>
using namespace std;

int main() {

    cout << "Content-type:text/html\r\n\r\n";

    string query = getenv("QUERY_STRING");
    string category = "All";

    // Extract category from URL
    if (query.find("category=") != string::npos) {
        category = query.substr(query.find("=") + 1);
    }

    ifstream file("C:/xampp/orders.csv");  // IMPORTANT PATH
    string line;

    map<string, int> productSales;

    getline(file, line); // skip header

    while (getline(file, line)) {

        stringstream ss(line);
        string orderID, product, cat, region, qtyStr, price;

        getline(ss, orderID, ',');
        getline(ss, product, ',');
        getline(ss, cat, ',');
        getline(ss, region, ',');
        getline(ss, qtyStr, ',');
        getline(ss, price, ',');

        int quantity = stoi(qtyStr);

        // FILTER CATEGORY
        if (category != "All" && cat != category)
            continue;

        productSales[product] += quantity;
    }

    file.close();

    // HTML OUTPUT
    cout << "<html><head>";
    cout << "<title>Supply Chain Results</title>";
    cout << "<link rel='stylesheet' href='/result.css'>";
    cout << "</head><body>";
    cout << "<main class='portal-card wide'>";
    cout << "<div class='badge'>SC</div>";

    cout << "<h2>Supply Chain Results</h2>";
    cout << "<h3>Category: " << category << "</h3>";

    cout << "<table>";
    cout << "<tr><th>Product</th><th>Total Quantity</th></tr>";

    for (auto &p : productSales) {
        cout << "<tr><td>" << p.first << "</td><td>" << p.second << "</td></tr>";
    }

    cout << "</table>";

    cout << "<a href='/index.html'>Back</a>";

    cout << "</main>";
    cout << "</body></html>";

    return 0;
}
