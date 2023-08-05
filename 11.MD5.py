import hashlib 
result = hashlib.md5(b'Python Pool') 
print("Hash Value : ", end ="")
print(result)
print("Equivalent Byte : ", end ="") 
print(result.digest())
print("Hexadecimal Equivalent : ", end ="") 
print(result.hexdigest()) 
