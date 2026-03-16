#Aula 16/03 Demanda, potência e Fator de Potência 
#Inserção de dados pelo usuário

#Valores que serão inseridos: PU ----> Potência Útil, em Watts 
#n ----> rendimento ---> n = PU / P 
#FP ----> fator de potência ou cosPhi ---->fp = P / S 

# PU, n, FP
# 3000, 0.76, 0.8

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

