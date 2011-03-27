
1. Plugins.lst文件格式, 暂考虑插件DLL与执行程序在同一目录下.

PLUGIN_LST_HEADER
FUNC_PLUGIN_NUM=%d
a.fpl
b.fpl
...
DATA_PLUGIN_NUM=%d
a.dpl
b.dpl

考虑功能插件、数据插件抽象基类CPluginBase

2. 消息处理

2.1) 窗口消息
2.2) 用户自定义消息
