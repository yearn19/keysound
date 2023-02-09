# keysound
window下按键鼠标音效，包括二次元音、鸡你太美、钢琴音、Cedar、音游模式、起风了、疾风剑豪、知夏轴、麻将音、蜂鸣器、木鱼音、雨滴音

程序下载后直接运行MFC2.exe即可，注意程序所在路径中不能有空格

在右下角任务图标里可以找到此程序，不过图标是透明的，也就是说会看不到，不过当鼠标移上去的时候就会有选项菜单了

如果提示缺少xxx.dll，就去安装Visual_C RuntimePack_3.0.22.0317.exe

可以随意更换音效（文件名中不能出现空格）

文件名基本就是模式的英语或汉语拼音

可以随机更换音效文件、wav格式就可以（我用AU直接导出来的wav格式次程序无法播放，在网上在线程序又转了一遍）

随机模式绑定文件夹random

键名模式绑定文件夹keyname用于存放指定的按键，键名首字母大写，如Shift.wav，未指定的按键，随机抽取keyname_default文件夹下的一个音效播放，如果keyname_default文件夹为空，则未指定的不播放

Cedar模式文件夹结构同keyname

钢琴音、疾风剑豪模式也是制定键名播放，不指定的会播放文件夹下的default.wav文件

其他模式均为随机播放文件夹下音频资源

起风了模式比较特殊，如果是快打，会播放一段段旋律，如果是慢打则随机播放

程序目前有两个比较明显的问题，CPU资源占用率过高，在我的电脑上可以达到10%-15%，有一定概率的按键监听不到

程序改编自[https://www.bilibili.com/video/BV1LA411r7uE/?spm_id_from=333.999.0.0&vd_source=3ddab8de3e8ea0ade0d26715bf892df7](https://www.bilibili.com/video/BV1LA411r7uE/?spm_id_from=333.999.0.0&vd_source=3ddab8de3e8ea0ade0d26715bf892df7)
程序本身并没有做太大的改动，主要是加入了更多的音效
