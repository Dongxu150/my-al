# 在这里写一些关于github的使用
# b站链接用来学习git https://www.bilibili.com/video/BV1B14y1J79b/?spm_id_from=333.337.search-card.all.click&vd_source=42078243e944ea37f009af96feeeb282
# 首先，创建一个新的文件夹
# mkdir learn
# 然后使用 git init 初始化
# 创建一个文件 vim introduction.py
# git status 可以用来查看当前工作区的状态
# git add 命令将修改后的文件添加到暂存区中
# 暂存区（Staging Area）是 Git 中的一个重要概念，也称为“索引（Index）”。
# 它是介于工作区（Working Directory）和 Git 仓库（Repository）之间的一个临时区域，
# 用于存储即将提交到 Git 仓库中的更改。
# 使用 git to .将文件送入缓存区
# git commit -m "first commit" 命令用于将暂存区中的文件提交到 Git 仓库中，并添加一条提交信息。
# 创建链接 git remote add origin https://github.com/Dongxu150/my-al.git
# 命令用于将本地 Git 仓库与远程 Git 仓库关联起来
# git config --global user.email "dxm@dlmu.edu.cn"
# git config --global user.name "Dongxu150"
# git push -u origin master 发送更改