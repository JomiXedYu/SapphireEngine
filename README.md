# Sapphire
A game engine.  

![](https://img.shields.io/github/license/JomiXedYu/JxCode.CoreLib?style=for-the-badge)
![](https://img.shields.io/badge/StdVer-C++20-blueviolet.svg?style=for-the-badge&logo=c%2B%2B)

迭代中功能列表

- 对象基础库使用JxCode.CoreLib
- 图形基础单元库：Vector3, Matrix等
- 资源管线: 
  - 以guid标识的资产引用
  - 支持序列化与编译资产包
  - 自定义asset importer
- 可编程渲染管线：可以自定义shader工作流程，物体剔除等。
  - 通过资源管线导入的shader配置文件，来控制framebuffer的创建，多pass渲染，渲染队列等内容。
  - 默认可编程渲染管线下的后处理：
    - Bloom
    - SSAO
    - SSR
- PBR工作流
  - PBR材质，shader
- 场景管理
  - 场景对象关系使用Node节点控制，而靠Component挂载编写功能。
  - 各级Node的通信使用消息机制，如OnUpdate，可以自行添加消息与消息实现。

后续功能列表
- 使用QT开发的Editor
- 图形抽象层，以便后续的引入vulkan
- 3d骨骼动画的支持
- 整合物理与碰撞模块
