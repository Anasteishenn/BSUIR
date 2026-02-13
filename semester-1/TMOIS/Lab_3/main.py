def input_set(prompt):
    items = input(prompt).strip().split()
    return set(items)


def input_graph(prompt):
    raw = input(prompt).strip()
    if not raw:
        return set()
    pairs = raw.split(",")
    result = set()
    for p in pairs:
        a, b = p.strip().split()
        result.add((a, b))
    return result


def union_rel(g1, g2):
    return {
        "X": g1["X"] | g2["X"],
        "Y": g1["Y"] | g2["Y"],
        "G": g1["G"] | g2["G"]
    }


def intersection_rel(g1, g2):
    return {
        "X": g1["X"] & g2["X"],
        "Y": g1["Y"] & g2["Y"],
        "G": g1["G"] & g2["G"]
    }


def difference_rel(g1, g2):
    return {
        "X": g1["X"] - g2["X"],
        "Y": g1["Y"] - g2["Y"],
        "G": g1["G"] - g2["G"]
    }


def inverse_rel(g):
    return {
        "X": g["Y"],
        "Y": g["X"],
        "G": {(y, x) for (x, y) in g["G"]}
    }


def composition_rel(g1, g2):
    comp_g = {
        (x, z)
        for (x, y1) in g1["G"]
        for (y2, z) in g2["G"]
        if y1 == y2
    }
    return {
        "X": g1["X"],
        "Y": g2["Y"],
        "G": comp_g
    }


def print_rel(name, rel):
    print(f"\n{name}:")
    print(" X =", rel["X"])
    print(" Y =", rel["Y"])
    print(" G =", rel["G"])


# ---------------- MAIN PROGRAM ------------------

print("=== Ввод соответствия Γ1 ===")
X = input_set("Введите множество X (через пробел): ")
Y = input_set("Введите множество Y (через пробел): ")
G1 = input_graph("Введите пары графа G1 ('a b, c d, ...'): ")

Gamma1 = {"X": X, "Y": Y, "G": G1}

print("\n=== Ввод соответствия Γ2 ===")
M = input_set("Введите множество M (через пробел): ")
N = input_set("Введите множество N (через пробел): ")
G2 = input_graph("Введите пары графа G2 ('a b, c d, ...'): ")

Gamma2 = {"X": M, "Y": N, "G": G2}


while True:

    print("1 — Объединение Γ1 и Γ2")
    print("2 — Пересечение Γ1 и Γ2")
    print("3 — Разность Γ1 \\ Γ2")
    print("4 — Инверсия Γ1")
    print("5 — Инверсия Γ2")
    print("6 — Композиция Γ1 * Γ2")
    print("0 — Выход")

    choice = input("Выберите пункт: ").strip()

    if choice == "1":
        print_rel("Объединение Γ1 ∪ Γ2", union_rel(Gamma1, Gamma2))

    elif choice == "2":
        print_rel("Пересечение Γ1 ∩ Γ2", intersection_rel(Gamma1, Gamma2))

    elif choice == "3":
        print_rel("Разность Γ1 \\ Γ2", difference_rel(Gamma1, Gamma2))

    elif choice == "4":
        print_rel("Инверсия Γ1⁻¹", inverse_rel(Gamma1))

    elif choice == "5":
        print_rel("Инверсия Γ2⁻¹", inverse_rel(Gamma2))

    elif choice == "6":
        print_rel("Композиция Γ1 ○ Γ2", composition_rel(Gamma1, Gamma2))

    elif choice == "0":
        print("Выход из программы.")
        break

    else:
        print("Неверный ввод, попробуйте ещё раз.")
