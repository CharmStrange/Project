# 시세 변수
High = 50
Middle = 100
Middle_Low = 150
Low = 200

class ProfitMaximizer:

    def __init__(self, GR, D, W, GL) : # GR, D, W, GL 에 1 batch 에서 기대되는 내용물 수 넣기
        self.GR = GR
        self.D = D
        self.W = W
        self.GL = GL

    def Fit(self, batch_size) :
        if ((self.GR * batch_size) // Low) : print("Profitable : Grass Seed\n")
        else : print("Non-Profitable : Grass Seed\n")

        if ((self.D * batch_size) // Middle) : print("Profitable : Door Seed\n")
        else : print("Non-Profitable : Door Seed\n")

        if ((self.W * batch_size) // Low) : print("Profitable : Wood Block Seed\n")
        else : print("Non-Profitable : Wood Block Seed\n")

        if ((self.GL * batch_size) // Middle) : print("Profitable : Glass Pane Seed\n")
        else : print("Non-Profitable : Glass Pane Seed\n")

    def remain(self, batch_size) :
        GR_r = (self.GR * batch_size) % Low
        D_r = (self.D * batch_size) % Middle
        W_r = (self.W * batch_size) % Low
        GL_r = (self.GL * batch_size) % Middle

        if ((self.GR * batch_size) // Low) : print(f"Grass Seed : {GR_r}\n")
        else : print("No remains!\n")

        if ((self.D * batch_size) // Middle) : print(f"Door Seed : {D_r}\n")
        else : print("No remains!\n")

        if ((self.W * batch_size) // Low) : print(f"Wood Block Seed : {W_r}\n")
        else : print("No remains!\n")

        if ((self.GL * batch_size) // Middle) : print(f"Glass Pane Seed : {GL_r}\n")
        else : print("No remains!\n")

    def MeanCmp(self) :
        meancmp_GR = means[0] - self.GR
        meancmp_D = means[1] - self.D
        meancmp_W = means[2] - self.W
        meancmp_GL = means[3] - self.GL

        print(f"Difference between the mean of Grass Seeds and {self.GR} : {meancmp_GR}")
        print(f"Square of the difference between the mean of Grass Seeds and {self.GR} : {meancmp_GR**2}\n")

        print(f"Difference between the mean of Door Seeds and {self.D} : {meancmp_D}")
        print(f"Square of the difference between the mean of Door Seeds and {self.D} : {meancmp_D**2}\n")

        print(f"Difference between the mean of Wood Block Seeds and {self.W} : {meancmp_W}")
        print(f"Square of the difference between the mean of Wood Block Seeds and {self.W} : {meancmp_W**2}\n")

        print(f"Difference between the mean of Grass Seeds and {self.GL} : {meancmp_GL}")
        print(f"Square of the difference between the mean of Glass Pane Seeds and {self.GL} : {meancmp_GL**2}\n")
