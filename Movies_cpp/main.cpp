#include <iostream>

using namespace std;

struct Movies
{
    string name;
    string director;
    int year;
};

void getMovieInfo(Movies &); // Pass by reference with modifications allowed.
void showMovieInfo(const Movies &); // Pass by reference, but no modifications allowed.

int main()
{
    Movies myMovie;

    getMovieInfo(myMovie);
    showMovieInfo(myMovie);

    return 0;


}
void getMovieInfo(Movies &myMovie)
{
     cout << "Enter the following information about your "
         << "favourite movie " << endl
         << "Name: ";
    getline(cin, myMovie.name);

    cout << "Director: ";
    getline(cin, myMovie.director);

    cout << "Release Date: ";
    cin >> myMovie.year;
}
void showMovieInfo(const Movies &myMovie)
{
      cout << "The information you entered for the movie is below: " << endl;
    cout << "Movie name:    " << myMovie.name << endl
         << "Director:      " << myMovie.director << endl
         << "Year released: " << myMovie.year << endl;
}
