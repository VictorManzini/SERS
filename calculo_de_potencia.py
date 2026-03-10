#Aula 9/3 Demanda e Potência 
#Entrada de dados 
PU = int(input ("Insira a potência útil do motor: "))
n = float(input("Insira o valor do rendimento (de 0 a 1): "))

# Cálculo de potência ativa 
# n = PU / P 
P = PU / n
print(f"A potência ativa do motor é: {int(P)} W")


