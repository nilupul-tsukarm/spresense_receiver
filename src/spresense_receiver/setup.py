from setuptools import find_packages, setup

package_name = 'spresense_receiver'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools', 'requests', 'opencv-python', 'cv_bridge'],
    zip_safe=True,
    maintainer='ns',
    maintainer_email='ns@todo.todo',
    description='ROS 2 package to receive images and ToF data from Spresensen',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'spresense_receiver = spresense_receiver.spresense_receiver:main',
        ],
    },
)
