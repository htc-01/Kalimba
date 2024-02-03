stm32开发板详细型号:stm32f103c8t6最小系统板
长这个样子：
![63a002a153a781674b90f97966509f2](https://github.com/htc-01/Kalimba/assets/77454549/a9a03576-c1e8-44d3-b037-6b8f5f4948a4)

接线方式 （keyx为第x个按钮）：
GND→key1→GPIOA15；
GND→key2→GPIOA12；
GND→key3→GPIOA1；
GND→key4→GPIOA8；
GND→key5→GPIOA7；
GND→key6→GPIOA6；
GND→key7→GPIOA5；
GND→key8→GPIOA4；
GND→key9→GPIOA3；
GND→key10→GPIOA2；
GPIOB10→蜂鸣器→GPIOB11；
烧录方式：
1.安装keil5；
  jlink或stlink，直接在此界面选择相应的下载工具，然后f8烧录即可
![image](https://github.com/htc-01/Kalimba/assets/77454549/8229fe50-de4b-4fc7-ad5b-d8ecd682a692)
2. ch340；
 (1)下载ch340驱动
（2）下载flymcu软件
ch340接线：
3v3→3.3；
GND→GND；
rxd→GPIOA9；
txd→GPIOA10；
（3）再主界面中选择.hex文件（Objects\111111.hex）
boot0设置为1（就是最右边的那个跳线帽，给它拽到下面去）
ch340连接电脑，点击flymcu主界面上的“开始编程”
（4）boot设置回0，并按一下旁边的按钮，不出意外的话便可正常运行
