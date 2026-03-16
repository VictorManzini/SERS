#Aula 16/03 Exercicios: Calcule aas potências ativa, aparente e reativa para os motores das especificações
# disponíveis na pasta da aula
#Inserção de dados pelo usuário

#Valores que serão inseridos: PU ----> Potência Útil, em Watts 
#n ----> rendimento ---> n = PU / P 
#FP ----> fator de potência ou cosPhi ---->fp = P / S 

# PU, n, FP 
#Você encontra os dados na placa do motor. PU está em Kw, n está em rend. FP está em F.P
#Motor 1: PU = 750 W, n = 83.0, FP = 0.82
#Motor 2: PU = 7500 W, n = 91.0, FP = 0.82
#Motor 3: PU = 1260 W, n = 0.85, FP = 0.89
#Motor 4: PU = 30000 W, n = 95.8, FP = 0.89

#Entrada de dados 
PU = int(input ("Insira a potência útil do motor: "))
n = float(input("Insira o valor do rendimento (de 0 a 1): "))
FP = float(input("Insira o Fator de Potência (de 0 a 1):"))

# Cálculo das potências ativa (P), aparente (S) e reativa (Q)
# n = PU / P 
P = PU / n
# Cálculo da potência aparente (S)
S = P / FP
# Cálculo da potência reativa (Q)
# ** ---> operador de potenciação 
# **0.5 ---> extrai a raiz quadrada do resultado
Q = (S**2 - P**2)**0.5 

#f-string ---> permite imprimir string formatadas para que seja possível a impressão de variáveis
# (valores numéricos) na mesma estrutura, usando {}
print(f"A potência ativa do motor é: {int(P)} W")
print(f"A potência aparente do motor é: {int(S)} VA")
print(f"A potência reativa do mtor é: {int(Q)} VAr")

#Exemplo com casas decimais: 
#print(f"A potência ativa do motor é: {P: .2f} W")



