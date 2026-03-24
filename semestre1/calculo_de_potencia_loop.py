#Aula 9/3 Demanda e Potência 
#Mesma coisa que o calculo_de_potencia.py mas com um loop 

while True: 
    PU = input ("Insira a potência útil do motor (ou 'sair' para encerrar): ")
    if PU.lower() =='sair': 
        print("Encerrando o programa...")
        break

    n = input("Insira o valor de rendimento (de 0 a 1) (ou 'sair' para encerrar): ")
    if n.lower() =='sair':
        print("Encerrando o programa...")
        break

    P = int(PU) / float(n)
    print(f"A potência do motor é: {int(P)} W")
     




