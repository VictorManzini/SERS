print("Bem-vindos")

while True: 
    print("Analise de dados dos motores. Por favor insira apenas números.")

    
    PU = input ("Insira a potência útil do motor (ou 'sair' para encerrar): ")
    if PU.lower() == 'sair': 
        print("Encerrando o programa...")
        break

    n = input("Insira o valor do rendimento (de 0 a 1): ")
    if n.lower()== 'sair': 
        print("Encerrando o programa...")
        break

    FP = input("Insira o fator de potência (de 0 a 1): ")
    if FP.lower() == 'sair':
        print("Encerrando o programa...")
        break


    # Cálculo das potências ativa (P), aparente (S) e reativa (Q)
    # n = PU / P 
    P = int(PU) / float(n)
    # Cálculo da potência aparente (S)
    S = int(P) / float(FP)
    # Cálculo da potência reativa (Q)
    # ** ---> operador de potenciação 
    # **0.5 ---> extrai a raiz quadrada do resultado
    Q = (S**2 - P**2)**0.5

    print(f"A potência útil do motor é: {int(P)} W")
    print(f"A potência aparente do motor é: {int(S)} VA")
    print(f"A potência reativa do motor é: {int(Q)} VAr")

    input("Deseja continuar no programa? (s/n)")
    if input == "s":
        continue
    else:
        print("Obrigado por ter usado analise_motores_loop.py")
        print("Nos vemos em uma próxima vez!")
        print("Encerrando o programa...")
    
        break


#Valores que serão inseridos: PU ----> Potência Útil, em Watts 
#n ----> rendimento ---> n = PU / P 
#FP ----> fator de potência ou cosPhi ---->fp = P / S 

# PU, n, FP 
#Você encontra os dados na placa do motor. PU está em Kw, n está em rend. FP está em F.P
#Motor 1: PU = 750 W, n = 0.83, FP = 0.82
#Motor 2: PU = 7500 W, n = 0.91, FP = 0.82
#Motor 3: PU = 1260 W, n = 0.85, FP = 0.89
#Motor 4: PU = 30000 W, n = 0.958, FP = 0.89