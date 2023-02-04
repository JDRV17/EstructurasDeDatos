#Nombre: Juan Diego Rojas Valdés (Juan Rojas)
#Código: 8983626
#Punto 1)
def verificarDiagonales(mat):
    length=len(mat)
    diag1=[]
    for i in range (length):
        for j in range (length):
            if i==j:
                diag1.append(mat[i][j])
    diag2=[]
    for i in range (length):
        for j in range (length):
            if i==j:
                diag2.append(mat[i][(length-j)-1])    
    if diag1==diag2:
        flag= True
    else:
        flag= False   
    return "1", flag

#Punto 2)
def esCapicua(list):
    length=len(list)
    for i in range(length):
        if list[i]!=list[(length-1)-i]:
            flag= False
            break
        else:
            flag= True
    return "2", flag        

#Punto 3)
#Numeral a)
def diferenciaListas(list1,list2):
    length1=len(list1)
    length2=len(list2)
    dif=[]
    for i in range (length1):
        #print(list1.count(list1[i]))
        if list1[i] not in list2:
            dif.append(list1[i])
        else:
            if list1.count(list1[i])-list2.count(list1[i])>1:
                for j in range (list1.count(list1[i])-list2.count(list1[i])):
                    dif.append(list1[i]) 
                    
    return "3a", dif
print(diferenciaListas(list3,list4))

#Numeral b)
#def lectImpres():
  #  veces=input()
   # for i in range (veces):
    #    mat=input()
#lectImpres()

#Punto 4
def mostrarPrimos(N):
    print("Números primos del 1 al ",N,":")
    primos=[]
    primosdobles=[]
    primosdoblesreales=[]
    for i in range (N):
        cont=0
        for j in range (i):
            if j!=0:
                if i%j==0:
                    cont=cont+1
        if cont==1:
            primos.append(i)
            print("--->",i)
            string=str(i)
            num=list(string)
            suma=0
            k=0
            while k<=(len(num)-1):
                suma=suma+(int)(num[k])
                k=k+1
            for l in range(suma):
                cont2=0
                if l!=0:
                    if suma%l==0:
                        cont2=cont2+1
                if cont2==1:
                    primosdobles.append(i)
    for i in primosdobles:
        if primosdobles.count(i)==1:
            primosdoblesreales.append(i)
    print("Los números primos cuya suma de sus dígitos también son números primos son los siguientes: ",primosdoblesreales)

#Punto 5)
def sumarValoresMatriz(mat, par):
    matriz=[]
    lista=[]
    lugar=[]
    numero=[]
    keys=list(mat)
    for i in range(max(keys)+1):
        #print(i)
        if i in mat:
            for j in range (len(mat[i])):
                lugar.append(mat[i][j][0])
                #print(max(lugar))
                numero.append(mat[i][j][1])
                if i== 0:
                    for k in range (8):
                        print(mat[i][j][0])
                        while len(lista)<8:
                            if mat[i][j][0] == k:
                                lista.append(mat[i][j][1])
                            else:
                                lista.append(0)
        
    print(lista)
    #print(max(lugar))
    #print(numero)
sumarValoresMatriz(disp,par)

