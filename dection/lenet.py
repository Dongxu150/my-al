import torch
import numpy as np
import sys
import d2lzh_pytorch as d2lls
x = torch.ones(3,2,requires_grad = True)
print(x)
print(x.grad_fn)
y =x+2
print(y.grad_fn)
z = y*y +3
out = z.mean()
print(z,out)
out.backward()
print(x.grad)
out2 = x.sum()
print(out2)

x.grad.data.zero_()
out2.backward()
print(x.grad)
