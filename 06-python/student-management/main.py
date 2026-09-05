from models import StudentManager
from ui import menu_handler


def main():

    manager = StudentManager()

    while True:

        running = menu_handler.run(manager)

        if not running:
            break


if __name__ == "__main__":
    main()