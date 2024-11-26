//Q2
#include <iostream>
using namespace std;

int main() {
    int miners, toasters, fans;

    double minerPrice = 1500, toasterPrice = 200, fanPrice = 450;
    double minerDiscount = 0.05, toasterDiscount = 0.10, fanDiscount = 0.15;
    double taxRate = 0.10;

    cout << "Enter the number of miners: ";
    cin >> miners;
    cout << "Enter the number of toasters: ";
    cin >> toasters;
    cout << "Enter the number of fans: ";
    cin >> fans;

    //before discount
    double minerCost = miners * minerPrice;
    double toasterCost = toasters * toasterPrice;
    double fanCost = fans * fanPrice;

    // Calculate discounts
    minerCost -= minerCost * minerDiscount;
    toasterCost -= toasterCost * toasterDiscount;
    fanCost -= fanCost * fanDiscount;

    //after discounts
    double totalCost = minerCost + toasterCost + fanCost;

    // Add tax
    double tax = totalCost * taxRate;
    double finalCost = totalCost + tax;

    cout << "The total amount to be paid is Rs. " << finalCost << endl;

    return 0;
}
