import ui
from book import Book
class Library:
    def __init__(self):
        self.borrowers = []
        self.books = {}
        self.genre_prefixes = {
    "Fiction": "FIC",
    "Science": "SCI",
    "History": "HIS",
    "Technology": "TEC",
    "Fantast": "FAN",
    "POLITICS": "POL"}

    def add_book(self, title, author, genre, copies):

        prefix = self.genre_prefixes.get(genre)
        if prefix is None:
            answer = input('Do you want to create this genre? (Y/N)').lower()
            if answer == "y":
                genre_name = input('Provide genre name: ')
                genre_code = input("Provide genre code (must be 3 letters only)")
                self.genre_prefix[genre_name] = genre_code
                print(f'New genre: {genre_name} and Genre Code: {genre_code} created!')
            else:
                print("Refer to the existing genre")

        count = 0

        for book_id in self.books:
            if book_id.startswith(prefix):
                count += 1
                
        book_id = f"{prefix}{count + 1:03}"
        new_book = Book(book_id, title, author, genre, int(copies))
        self.books[book_id] = new_book

        print(f'Book {title} added successfully! ')


        
