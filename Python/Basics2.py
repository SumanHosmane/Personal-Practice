#Basics 2: XOR
#Suman Hosmane

buffer1 = '1c0111001f010100061a024b53535009181c'
buffer2 = '686974207468652062756c6c277320657965'
result = int(buffer1, 16) ^ int(buffer2, 16)
print('{:x}'.format(result))