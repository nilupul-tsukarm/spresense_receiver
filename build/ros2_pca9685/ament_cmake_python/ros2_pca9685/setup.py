from setuptools import find_packages
from setuptools import setup

setup(
    name='ros2_pca9685',
    version='1.0.0',
    packages=find_packages(
        include=('ros2_pca9685', 'ros2_pca9685.*')),
)
