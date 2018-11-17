import random
import time


def main():
    print("Codi per a les codificacions de l'assignatura de Xarxes")
    bits = [random.randint(0,1) for i in range(10)]
    print("Cadena original: ", bits)
    nonreturn_zero(bits)
    time.sleep(2)
    nonreturn_zero_level(bits)
    time.sleep(2)
    nonreturn_zero_inverted(bits)
    time.sleep(2)
    bipolar_ami(bits)
    time.sleep(2)
    pseudoternary(bits)
    time.sleep(2)
    manchester(bits)
    time.sleep(2)
    diff_manchester(bits)
    time.sleep(2)
    B8ZS(bits)
    time.sleep(2)
    HDB3(bits)

def nonreturn_zero(bits=[0 for i in range(10)]):
    print("Codificació Non-Return-Zero")
    time.sleep(1)
    print("Senyal original: ", bits)
    time.sleep(1)
    cod = []
    for i in bits:
        if i:
            cod.append(True)
        else:
            cod.append(False)
    print("Senyal codificada: ", cod)
    time.sleep(1)
    decod = []
    for i in cod:
        if i:
            decod.append(1)
        else:
            decod.append(0)
    print("Senyal decodificada", decod)
    print("\nDIFF: ", [bits[i] - decod[i] for i in range(10)], "\n")

def nonreturn_zero_level(bits=[0 for i in range(10)]):
    print("Codificació Non-Return to Zero Level")
    time.sleep(1)
    print("Senyal original: ", bits)
    time.sleep(1)
    cod = []
    for i in bits:
        if not i:
            cod.append(True)
        else:
            cod.append(False)
    print("Senyal codificada: ", cod)
    time.sleep(1)
    decod = []
    for i in cod:
        if not i:
            decod.append(1)
        else:
            decod.append(0)
    print("Senyal decodificada", decod)
    print("\nDIFF: ", [bits[i] - decod[i] for i in range(10)], "\n")

def nonreturn_zero_inverted(bits=[0 for i in range(10)]):
    print("Codificació Non-Return Zero Inverted")
    time.sleep(1)
    print("Senyal original: ", bits)
    time.sleep(1)
    cod = []
    for i in range(10):
        if i == 0:
            if bits[i]:
                cod.append(True)
            else:
                cod.append(False)
        else:
            if bits[i]:
                cod.append(not cod[i-1])
            else:
                cod.append(cod[i-1])
    print("Senyal codificada: ", cod)
    time.sleep(1)
    decod = []
    for i in range(10):
        if i == 0:
            if cod[i]:
                decod.append(1)
            else:
                decod.append(0)
        else:
            if cod[i] == cod[i-1]:
                decod.append(0)
            else:
                decod.append(1)
    print("Senyal decodificada", decod)
    print("\nDIFF: ", [bits[i] - decod[i] for i in range(10)], "\n")

def bipolar_ami(bits=[0 for i in range(10)]):
    print("Codificació Bipolar AMI")
    time.sleep(1)
    print("Senyal original: ", bits)
    time.sleep(1)
    cod = []
    last_high = False
    for i in bits:
        if i:
            if last_high:
                cod.append('low')
                last_high = not last_high
            else:
                cod.append('high')
                last_high = not last_high
        else:
            cod.append('zero')
    print("Senyal codificada: ", cod)
    time.sleep(1)
    decod = []
    for i in cod:
        if i != 'zero':
            decod.append(1)
        else:
            decod.append(0)
    print("Senyal decodificada", decod)
    print("\nDIFF: ", [bits[i] - decod[i] for i in range(10)], "\n")


def pseudoternary(bits=[0 for i in range(10)]):
    print("Codificació Pseudoternary")
    time.sleep(1)
    print("Senyal original: ", bits)
    time.sleep(1)
    cod = []
    last_high = False
    for i in bits:
        if not i:
            if last_high:
                cod.append('low')
                last_high = not last_high
            else:
                cod.append('high')
                last_high = not last_high
        else:
            cod.append('zero')
    print("Senyal codificada: ", cod)
    time.sleep(1)
    decod = []
    for i in cod:
        if i != 'zero':
            decod.append(0)
        else:
            decod.append(1)
    print("Senyal decodificada", decod)
    print("\nDIFF: ", [bits[i] - decod[i] for i in range(10)], "\n")


def manchester(bits=[0 for i in range(10)]): 
    print("Codificació Manchester")
    time.sleep(1)
    print("Senyal original: ", bits)
    time.sleep(1)
    cod = []
    for i in bits:
        if i:
            cod.append('low_to_high')
        else:
            cod.append('high_to_low')
    print("Senyal codificada: ", cod)
    time.sleep(1)
    decod = []
    for i in cod:
        if i == 'low_to_high':
            decod.append(1)
        else:
            decod.append(0)
    print("Senyal decodificada", decod)
    print("\nDIFF: ", [bits[i] - decod[i] for i in range(10)], "\n")


def diff_manchester(bits=[0 for i in range(10)]):
    print("Codificació Differential Manchester")
    time.sleep(1)
    print("Senyal original: ", bits)
    time.sleep(1)
    cod = []
    for i in bits:
        if i:
            cod.append('transition')
        else:
            cod.append('no transition')
    print("Senyal codificada: ", cod)
    time.sleep(1)
    decod = []
    for i in cod:
        if i == 'transition':
            decod.append(1)
        else:
            decod.append(0)
    print("Senyal decodificada", decod)
    print("\nDIFF: ", [bits[i] - decod[i] for i in range(10)], "\n")


def B8ZS(bits=[0 for i in range(10)]):
    # bits=[0,0,0,0,0,0,0,0,1,1]
    print("Codificació Bipolar 8 Zeros Substitution")
    time.sleep(1)
    print("Senyal original: ", bits)
    time.sleep(1)
    cod_AMI = []
    last_high = False
    for i in bits:
        if i:
            if last_high:
                cod_AMI.append('low')
                last_high = not last_high
            else:
                cod_AMI.append('high')
                last_high = not last_high
        else:
            cod_AMI.append('zero')
    cod = []
    print(cod_AMI)
    eight_pos = ['zero', 'zero', 'zero', 'high', 'low', 'zero', 'low', 'high']
    eight_neg = ['zero', 'zero', 'zero', 'low', 'high', 'zero', 'high', 'low']
    zeros_in_row = 0
    last_pulse = 'high'
    for i in range(10):
        if cod_AMI[i] != 'zero':
            cod.append(cod_AMI[i])
            zeros_in_row = 0
            last_pulse = cod_AMI[i]
        else:
            if zeros_in_row == 7:
                if last_pulse == 'high':
                    cod[i-7:i+1] = eight_pos
                else:
                    cod[i-7:i+1] = eight_neg
                zeros_in_row = 0
            else:
                cod.append('zero')
                zeros_in_row += 1
    print("Senyal codificada: ", cod)
    time.sleep(1)
    decod = []
    next_zero = False
    last = None
    for i in range(10):
        if next_zero:
            decod.append(0)
            next_zero = False
        else:
            if cod[i] == 'zero':
                decod.append(0)
            else:
                if cod[i] == 'high' and last != 'high':
                    decod.append(1)
                    last = 'high'
                elif cod[i] == 'low' and last != 'low':
                    decod.append(1)
                    last = 'low'
                else:
                    decod[i-3:i+1] = [0]*4
                    next_zero = True
    print("Senyal decodificada", decod)
    print("\nDIFF: ", [bits[i] - decod[i] for i in range(10)], "\n")


def HDB3(bits=[0 for i in range(10)]):
    print("Codificació Bipolar AMI")
    time.sleep(1)
    print("Senyal original: ", bits)
    time.sleep(1)
    four_neg_odd = ['zero', 'zero', 'zero', 'low']
    four_pos_odd = ['zero', 'zero', 'zero', 'high']
    four_pos_even = ['low', 'zero', 'zero', 'low']
    four_neg_even = ['high', 'zero', 'zero', 'high']
    cod = []
    for i in range(10):
        pass
    print("Senyal codificada: ", cod)
    time.sleep(1)
    decod = []
    for i in range(10):
        pass
    print("Senyal decodificada", decod)

main()
