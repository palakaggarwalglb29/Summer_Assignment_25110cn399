#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Structure to hold individual Movie details
struct Movie {
    int id;
    string title;
    string time;
    double price;
    int availableSeats;
};

// Class handling the Ticketing System Operations
class TicketBookingSystem {
private:
    vector<Movie> movies;
    const int TOTAL_SEATS = 50;

public:
    // Constructor initializes sample movies
    TicketBookingSystem() {
        movies.push_back({1, "Inception", "10:00 AM", 12.50, TOTAL_SEATS});
        movies.push_back({2, "Interstellar", "01:30 PM", 14.00, TOTAL_SEATS});
        movies.push_back({3, "The Dark Knight", "05:00 PM", 15.00, TOTAL_SEATS});
        movies.push_back({4, "Avatar: Way of Water", "08:30 PM", 18.00, TOTAL_SEATS});
    }

    // Function to display all available movies and timings
    void displayMovies() {
        cout << "\n======================================================\n";
        cout << "                 AVAILABLE SHOWS                      \n";
        cout << "======================================================\n";
        cout << left << setw(5) << "ID" 
             << setw(25) << "Movie Title" 
             << setw(12) << "Showtime" 
             << setw(10) << "Price" 
             << "Available Seats\n";
        cout << "------------------------------------------------------\n";
        
        for (const auto& movie : movies) {
            cout << left << setw(5) << movie.id 
                 << setw(25) << movie.title 
                 << setw(12) << movie.time 
                 << "$" << setw(9) << fixed << setprecision(2) << movie.price 
                 << movie.availableSeats << " / " << TOTAL_SEATS << "\n";
        }
        cout << "======================================================\n";
    }

    // Function to execute ticket purchase operations
    void bookTicket() {
        int movieId, seatsToBook;
        displayMovies();

        cout << "\nEnter the Movie ID you want to book: ";
        cin >> movieId;

        // Input validation for finding the selected movie
        Movie* selectedMovie = nullptr;
        for (auto& movie : movies) {
            if (movie.id == movieId) {
                selectedMovie = &movie;
                break;
            }
        }

        if (selectedMovie == nullptr) {
            cout << "\n[ERROR] Invalid Movie ID. Returning to main menu.\n";
            return;
        }

        cout << "Enter the number of seats to book: ";
        cin >> seatsToBook;

        // Seating availability confirmation check
        if (seatsToBook <= 0) {
            cout << "\n[ERROR] Invalid seat quantity selected.\n";
            return;
        }

        if (selectedMovie->availableSeats < seatsToBook) {
            cout << "\n[ERROR] Sorry, only " << selectedMovie->availableSeats 
                 << " seats are available for this show.\n";
            return;
        }

        // Processing transaction calculations
        double totalCost = selectedMovie->price * seatsToBook;
        selectedMovie->availableSeats -= seatsToBook;

        // Print transactional receipt
        cout << "\n======================================================\n";
        cout << "               BOOKING CONFIRMED!                     \n";
        cout << "======================================================\n";
        cout << "Movie:        " << selectedMovie->title << "\n";
        cout << "Showtime:     " << selectedMovie->time << "\n";
        cout << "Seats Booked: " << seatsToBook << "\n";
        cout << "Total Price:  $" << fixed << setprecision(2) << totalCost << "\n";
        cout << "======================================================\n";
    }
};

// Main Driver Function
int main() {
    TicketBookingSystem system;
    int choice;

    do {
        cout << "\n--- TICKET BOOKING SYSTEM MENU ---\n";
        cout << "1. View Available Movie Shows\n";
        cout << "2. Book Movie Tickets\n";
        cout << "3. Exit System\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.displayMovies();
                break;
            case 2:
                system.bookTicket();
                break;
            case 3:
                cout << "\nThank you for using our Ticket Booking System. Goodbye!\n";
                break;
            default:
                cout << "\n[ERROR] Invalid option selected. Please choose between 1 and 3.\n";
        }
    } while (choice != 3);

    
}
