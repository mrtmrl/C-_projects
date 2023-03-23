#include <iostream>
#include <string>

using namespace std;

class Film
{
    string name;
    string type;
    double film_registration_fee;
    public:
    Film(string n,string t)
    {
        name = n;
        type = t; 
    }
    string getName()
    {
        return name;
    }
    void setFee(double fee)
    {
        film_registration_fee = fee;
    }
    string getType()
    {
        return type;
    }
    double getFee()
    {
        return film_registration_fee;
    }
    friend double calculateMonthlyFee(Film f);

    void add()
    {
        double fee = calculateMonthlyFee(*this);
        setFee(fee);
    }    
};

double calculateMonthlyFee(Film f)
{
    double daily_fee;
    if (f.getType() == "Animation")
    {
        daily_fee = 11.0;
    }
    else if (f.getType() == "Action")
    {
        daily_fee = 17.0;
    }
    else 
    {
        daily_fee = 15.0;
    }

    f.setFee(daily_fee * 30);
    return f.getFee();
}

int main()
{
    Film films[2] = { Film("ToyStory" , "Animation"), Film("Avatar" , "Sci-Fi")};

    int film_count;
    char selection;
    
    do
    {
        cout << "Do you want to add or watch a film (A/W)," << endl;
        cout << "or enter (C) for exit the system: ";
        cin >> selection;

        switch (selection)
        {
        case 'a':
        case 'A':
        {
            for (film_count = 0; film_count < 2; film_count++)
            {
                string name,type;
                cout << "Enter the name of the film to be added: ";
                cin >> name;
                cout << "The film name: " << name << " is added." << endl;
                cout << "Enter the type: ";
                cin >> type;
                cout << "The type of the film: " << type << endl;
                Film newFilm(name, type);
                newFilm.add();
                films[0] = films[1];
                films[1] = newFilm;
            }
            break;
        }
        case 'w':
        case 'W':
        {
            int movieNum;
            int i=0;
            cout << "Enter the number films: " << endl;
            cin >> movieNum;
            if (movieNum < 1 || movieNum > sizeof(films) / sizeof(films[0]))
            {
                cout << "Invalid movie number" << endl;
            }
            else
            {
                cout << "Enter " << movieNum << " film names:" << endl;                
                    Film selectedFilm = films[movieNum-1];
                    double monthlyFee = calculateMonthlyFee(selectedFilm);
              while(i < movieNum)
              {
                    cout << "Enter the name of the movie: " << selectedFilm.getName() << endl;
                    cout << "Enter the type of the movie: " << selectedFilm.getType() << endl;
                    cout << "You've watched film, and  type of the film is " << selectedFilm.getType() << endl;
                    cout << "Film Archive Fee Details:" << endl;
                    cout << "-------------------------------------------------------" << endl;
                    cout << "Monthly rent fee: " << monthlyFee << "TL" << endl;
                    cout <<"--------------------------------------------------------" << endl;
                    i++;
              }
            }
            break;
        }
        case 'c':
        case 'C':
        {
            cout << "Exit the system." << endl;
            break;
        }
        default:
        {
            cout << "Invalid transaction" << endl;
            break;
        }
        }
    }
    while (selection != 'c' && selection != 'C');
    return 0;
}
