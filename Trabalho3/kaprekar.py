def kaprekar_steps(n):
    # Verifica se a entrada é válida: número natural de 4 dígitos e sem todos os dígitos iguais
    test = list(str(n))
    first = test[0]
    valid = False
    for i in range(len(test)):
        if test[i] != first:
            valid = True
    if n < 1000 or n > 9999 or not valid:
        return "entrada invalida."

    KAPREKAR_CONSTANT = 6174
    steps = 0

    while n != KAPREKAR_CONSTANT:
        # Converte o número em string para manipular os dígitos
        digits = f"{n:04d}"

        # Ordena os dígitos em ordem decrescente e crescente
        desc = int("".join(sorted(digits, reverse=True)))
        asc = int("".join(sorted(digits)))

        # Subtração
        n = desc - asc
        steps += 1

    return steps


# Leitura da entrada
try:
    entrada = int(input("Digite um número natural de quatro dígitos: "))
    print(kaprekar_steps(entrada))
except ValueError:
    print("entrada invalida.")
