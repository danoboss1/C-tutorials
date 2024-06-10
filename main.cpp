#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void print_empty_line_n_times(int number_of_empty_lines){
    for(int i = 0; i < number_of_empty_lines; i++){
        cout << "\n";
    }

    return;
}

string ask_for_currency(){
    int currency_choice;
    string currency;

    cout << "Enter number for a desired currency" << endl;
    cout << "1 - dollar, 2 - rupee, 3 nigerian naira" << endl;

    cin >> currency_choice;

    switch(currency_choice) {
        case 1:
            currency = "Dollars";
            break;
        case 2:
            currency = "Rupees";
            break;
        case 3:
            currency = "Nigerian Nairas";
            break;
    }

    return currency;
}

string draw_intro_page(){
    string decorator = "<><><><><><><><><>";
    string name;

    cout << decorator << endl;
    cout << "Currency converter" << endl;
    cout << decorator << endl;

    cout << "Please enter your name: ";
    
    getline(cin, name);
    return name;
}

void convert_money(const unordered_map<string, double>& exchange_rates){
    string currency_to;
    int amount;
    
    cout << "Choose currency u want to convert Euros to" << endl; 
    currency_to = ask_for_currency();

    cout << "Choose amount u want to convert" << endl;
    cin >> amount;

    double rate = exchange_rates.at(currency_to);
    double converted_amount = amount * rate;

    cout << "U have converted " << amount << " Euros" << " to " << currency_to << endl;
    cout << "U will recive " << converted_amount << " " << currency_to << endl;
}


int main(){
    string login;
    
    // exchange rates relative to he Euro
    unordered_map<string, double> exchange_rates = {
        {"Dollars", 1.18},
        {"Rupees", 88.0},
        {"Nigerian Nairas", 480.0}
    }; 

    login = draw_intro_page();

    print_empty_line_n_times(2);
    cout << "Hello, " << login << "!" << endl;

    convert_money(exchange_rates);

    return 0;
}