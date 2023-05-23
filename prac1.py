size = 3
clientList=[None]*size

def add():
    clientId=int(input("Enter Id: "))
    name = input("client name")
    telephone = input("client telephone")
    clientDetails = [clientId,name,telephone]

    index = clientId%size
    for i in range(size):
        if clientList[index]==None:
            clientList[index]=clientDetails
            print("Adding data ", index,clientDetails)
            break
        else:
            index = (index+1)%size
            
def search():
    clientId = int(input("Enter Id:"))
    index = clientId%size
    for i in range(size):
        if clientList[index]!=None:
            if clientList[index][0]==clientId:
                print("client found at index ",index,clientList[index])
                break
        index = (index+1)%size
                
    else:
        print("element not found")

def delete():
    clientId=int(input("Enter clientId you want to delete."))
    index = clientId%size
    for i in range(size):
        if clientList[index]!=None:
            if clientList[index][0]==clientId:
                clientList[index]=None
                print("client deleted.")
                break
        index = (index+1)%size
    else:
        print("Print element not found")

add()
add()
add()
print("Search client")
search()
print("delete client")
delete()
print("Search client")
search()
