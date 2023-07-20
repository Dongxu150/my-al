import torch
import torchvision
import torch.nn as nn
import time
import sys
import d2lzh_pytorch as d2l
import matplotlib.pyplot as  plt
import torchvision.transforms as transforms
# 另外我们还指定了参数transform = transforms.ToTensor()
# 使所有数据转换为Tensor，如果不进行转换则返回的是PIL图片。
# transforms.ToTensor()将尺寸为 (H x W x C) 
# 且数据位于[0, 255]的PIL图片或者数据类型为np.uint8
# 的NumPy数组转换为尺寸为(C x H x W)且数据类型为torch.float32且位于[0.0, 1.0]的Tensor。
mnist_train = torchvision.datasets.FashionMNIST(root='~/Datasets/FashionMNIST', train=True, download=True, transform=transforms.ToTensor())
mnist_test = torchvision.datasets.FashionMNIST(root='~/Datasets/FashionMNIST', train=False, download=True, transform=transforms.ToTensor())
print(type(mnist_train))
print(len(mnist_train), len(mnist_test))
feature, label = mnist_train[0]
print(feature.shape, label)  # Channel x Height x Width
# 本函数已保存在d2lzh包中方便以后使用
def get_fashion_mnist_labels(labels):
    text_labels = ['t-shirt', 'trouser', 'pullover', 'dress', 'coat',
                   'sandal', 'shirt', 'sneaker', 'bag', 'ankle boot']
    return [text_labels[int(i)] for i in labels]

batch_size = 256
train_iter, test_iter = d2l.load_data_fashion_mnist(batch_size)

