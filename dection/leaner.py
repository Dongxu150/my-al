import torch
from IPython import display
from matplotlib import pyplot as plt
import numpy as np
import random
import torch.utils.data as Data
import torch.nn as nn
import torch.optim as optim
num_inputs = 2
num_examples = 1000
true_w = [2,-0.4]
true_b = 4.2
features =  torch.tensor(np.random.normal(0,1,(num_examples,num_inputs)),dtype = torch.float)
labels = true_b+true_w[0]*features[:,0]+true_w[1]*features[:,1]
labels = labels+torch.tensor(np.random.normal(0,0.01,size = labels.size()),dtype = torch.float)
dataset = Data.TensorDataset(features,labels)
batch_size = 40
data_iter = Data.DataLoader(dataset,batch_size,shuffle = True)

class linearnet(nn.Module):
    def __init__(self,n_feature):
        super(linearnet,self).__init__()
        # 这是初始化一个层
        self.features = nn.Linear(n_feature,1)
    def forward(self,x):
        y = self.features(x)
        return y
net = linearnet(num_inputs)
print(net)

print("---------------------")
for param in net.parameters():
    print(param)
# torch.nn仅支持输入一个batch的样本不支持单个样本输入，如果只有单个样本，可使用input.unsqueeze(0)来添加一维。
loss = nn.MSELoss()
optimizer = optim.SGD(net.parameters(),lr = 0.01)
# optimizer =optim.SGD([
#                 # 如果对某个参数不指定学习率，就使用最外层的默认学习率
#                 {'params': net.subnet1.parameters()}, # lr=0.03
#                 {'params': net.subnet2.parameters(), 'lr': 0.01}
#             ], lr=0.03)

print("------------------------")

num_epochs = 3
for epoch in range(1, num_epochs + 1):
    for X, y in data_iter:
        output = net(X)
        l = loss(output, y.view(-1, 1))
        optimizer.zero_grad() # 梯度清零，等价于net.zero_grad()
        # 反向传播梯度
        l.backward()
        # 更新参数
        optimizer.step()
    print('epoch %d, loss: %f' % (epoch, l.item()))

params_dict = net.state_dict()
print(optimizer.param_groups)
# 打印参数字典中的键和值
for name, param in params_dict.items():
    print(name, param.data)