#include <iostream>
#include <random>
#include <thread>
#include <chrono>
using namespace std;
int count = 0;
bool EndGame = false;
void timer() {
    int i = 0;
    while (true)
    {
        this_thread::sleep_for(chrono::milliseconds(1));
        if (EndGame == false) {
            if (i == 1000) {
                count++;
                i = 0;
            }
            else {
                i++;
            }
        }
        else {
            break;
        }

    }
}
int main() {
    thread Timer(timer);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 100);
    int input_number;
    int Number = dist(gen);
    int lang;
    int attempts = 0;
    cout<<"Choose a language:"<<endl;
    cout<<"1. Russian"<<endl;
    cout<<"2. English"<<endl;
    cin>>lang;
    if (lang == 1){
        while (true) {
            cout<<"Введите число:";
            cin>>input_number;
            if (input_number > Number) {
                cout<<"Слишком много!"<<endl;
                attempts++;
            }
            else if (input_number < Number) {
                cout<<"Слишком мало!"<<endl;
                attempts++;
            }
            else if (input_number == Number) {
                attempts++;
                cout<<"Ты угадал!"<<endl;
                EndGame = true;
                cout<<"Ваши попытки:" << attempts<<endl;
                Timer.join();
                cout<<"Ваше примерное итоговое время:" << count<<endl;
                break;
            }
        }
    }
    else if(lang == 2){
        while (true) {
            cout<<"Enter a number:";
            cin>>input_number;
            if (input_number > Number) {
                cout<<"Too much!"<<endl;
                attempts++;
            }
            else if (input_number < Number) {
                cout<<"Too little!"<<endl;
                attempts++;
            }
            else if (input_number == Number) {
                attempts++;
                EndGame = true;
                cout<<"you guessed it!"<<endl;
                cout<<"Your attempts:"<<attempts<<endl;
                Timer.join();
                cout<<"your approximate final time:"<<count<<endl;
                break;
            }
        }
    }
    return 0;
}
