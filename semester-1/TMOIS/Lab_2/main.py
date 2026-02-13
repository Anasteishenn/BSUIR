print("Введите график P (пример: a b, c d):")

P = [tuple(pair.strip().split()) for pair in input().replace("\n", "").replace("\r", "").split(",") if pair.strip()]

print("Введите график Q (пример: a b, b c):")
Q = [tuple(pair.strip().split()) for pair in input().replace("\n", "").replace("\r", "").split(",") if pair.strip()]

while True:
    print("\nВыберите операцию:")
    print("1 — Инверсия графика P")
    print("2 — Композиция P o Q")
    print("3 — pr1(P)")
    print("4 — pr2(P)")
    print("0 — Выход")

    choice = input("Ваш выбор: ")

    if choice == "1":
        inversed = [(y, x) for (x, y) in P]
        print("Инверсия графика P =", set(inversed))  

    elif choice == "2":
        composition = set(
            (x, y)
            for (x, z1) in P
            for (z2, y) in Q
            if z1 == z2
        )
        print("Композиция P ∘ Q =", composition)

    elif choice == "3":
        proj1 = {x for (x, _) in P}
        print("pr1(P) =", proj1)

    elif choice == "4":
        proj2 = {y for (_, y) in P}
        print("pr2(P) =", proj2)

    elif choice == "0":
        print("Выход.")
        break

    else:
        print("Некорректный ввод. Повторите.")
