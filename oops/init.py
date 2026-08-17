class Fruits:
    def __init__(self, fruitname,cost):
        # print(self)
        self.name = fruitname
        self.test = fruitname*5 
        self.cost = cost
        print("A new fruit in the basket")

f = Fruits("mango",50)
print(f.name)
print(f.test)
print(f.cost)