# FPN（Feature Pyramid Network，特征金字塔网络）是一种用于目标检测的深度学习网络结构。它的主要思想是在图像不同尺度下提取丰富的特征，并将这些特征级联起来，从而提高目标检测的准确性。

# 在传统的目标检测算法中，通常使用固定的图像尺寸来进行物体检测，但这种方法存在一些问题。例如，当物体大小不同时，使用相同的图像尺寸可能会导致物体过小或过大，从而导致检测失败。此外，不同尺度下的图像通常具有不同的特征，因此需要对不同尺度下的特征进行处理。

# FPN的主要思想是通过构建特征金字塔网络，从而在不同的尺度上提取具有不同语义的特征。具体而言，FPN通过在底层网络中添加额外的侧向连接，将高分辨率的低层特征与低分辨率的高层特征相结合。这样，FPN可以在不同的尺度上提取具有不同语义的特征，并将这些特征级联起来，从而提高目标检测的准确性。

# 在物体检测任务中，FPN通常与一些流行的目标检测算法（如Faster R-CNN、RetinaNet等）结合使用，从而提高检测的准确性。