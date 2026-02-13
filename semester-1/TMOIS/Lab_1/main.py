def main():
    U = set(map(int, input("Введите элементы универсума U через пробел: ").split()))
    print("Универсум U =", U)
    A = set(map(int, input("Введите элементы множества A через пробел: ").split()))
    B = set(map(int, input("Введите элементы множества B через пробел: ").split()))
    
    C = set()  # пустое множество

    print("Симметрическая разность множеств A и B:", C)


    if not A.issubset(U) or not B.issubset(U):
        print("\nНекоторые элементы множеств A или B не принадлежат универсуму U.")
        print("Рекомендуется, чтобы A и B были подмножествами универсума.\n")

    while True:
        print("\nВыберите операцию:")
        print("1 - Объединение (A или B)")
        print("2 - Пересечение (A и B)")
        print("3 - Разность (A \\ B)")
        print("4 - Разность (B \\ A)")
        print("5 - Симметрическая разность (A ^ B)")
        print("6 - Дополнение (U \\ A)")
        print("7 - Дополнение (U \\ B)")
        print("0 - Выход")

        choice = input("Ваш выбор: ")

        if choice == "1":
            print("Объединение (A или B):", A | B)
        elif choice == "2":
            print("Пересечение (A и B):", A & B)
        elif choice == "3":
            print("Разность (A \\ B):", A - B)
        elif choice == "4":
            print("Разность (B \\ A):", B - A)
        elif choice == "5":
            print("Симметрическая разность (A ^ B):", A ^ B)
        elif choice == "6":
            print("Дополнение (U \\ A):", U - A)
        elif choice == "7":
            print("Дополнение (U \\ B):", U - B)
        elif choice == "0":
            print("Выход из программы.")
            break
        else:
            print("Ошибка: выберите корректный пункт меню!")


if __name__ == "__main__":
    main()
