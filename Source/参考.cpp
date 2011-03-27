
    // 元素命令字符串
	const String STR_ELEMENT_DELETE				= "删除对象";
	const String STR_ELEMENT_PROPERTY			= "显示对象属性";

	// 数据层命令字符串
	//----------------------------------------------------------
	const String STR_CONTAINER_SELECT				= "选择数据层";
	const String STR_CONTAINER_UNSELECT				= "取消选择";
	const String STR_CONTAINER_DELETE				= "删除数据层";
	const String STR_CONTAINER_SET_AS_ACTIVE		= "设为活动";	
	//-----------------------------------------------------------
	const String STR_CONTAINER_CREATE_CHILD			= "创建数据层";
	const String STR_CONTAINER_ALL_CHILD_VISIBLE	= "显示所有数据层";
	const String STR_CONTAINER_ALL_CHILD_INVISIBLE	= "隐藏所有数据层";
	const String STR_CONTAINER_DELETE_ALL_CHILDREN	= "删除所有数据层";	
	const String STR_CONTAINER_DELETE_ALL_ELEMENTS	= "删除所有元素";
	const String STR_CONTAINER_EXPAND_ELE	= "展开元素";
	const String STR_CONTAINER_UN_EXPAND_ELE	= "隐藏元素";

	const String STR_CONTAINER_SET_DISP_SCALE	= "设置显示比例";
	

	//-----------------------------------------------------------
	const String STR_CONTAINER_PROPERTY				= "属性";

	static String ELEMENT_GUID = "{579FC6DD-B46D-42e9-9879-CCB7139119FA}";

	// {9537542C-9554-4ed8-BA10-7D0270E04C6A}
	const String CONTAINER_GUID = "{ 0x9537542c, 0x9554, 0x4ed8, { 0xba, 0x10, 0x7d, 0x2, 0x70, 0xe0, 0x4c, 0x6a } }";

	// 图层命令字符串
		//----------------------------------------------------------
		const String STR_OPEN_LAYER					= "打开";
		const String STR_CLOSE_LAYER				= "关闭";
		const String STR_OPEN_ELEMENT				= "打开";
		const String STR_CLOSE_ELEMENT				= "关闭";
		//----------------------------------------------------------	
		const String STR_ADD_LAYER					= "添加图层";
		const String STR_DEL_LAYER					= "删除图层";
		const String STR_ADD_ELEMENT				= "添加节点";
		const String STR_DEL_ELEMENT				= "删除节点";
		const String STR_RELT_ELEMENT				= "关联数据";
		const String STR_DEL_RELT					= "删除关联";	
		
		//-----------------------------------------------------------
		//-----------------------------------------------------------
		const String STR_PROPERTY_LAYER				= "属性";
		const String STR_PROPERTY_ELEMENT			= "属性";
		const String STR_SEPARATE1					= "分隔符1";
		const String STR_SEPARATE2					= "分隔符2";
		//-----------------------------------------------------------
		//-----------------------------------------------------------
		// ELEMENT 属性字段名称
		const String STR_NAME						= "Name";
		const String STR_CLASSNAME					= "ClassName";
		const String STR_DES						= "Des";
		const String STR_USERDATA					= "UserData";
		const String STR_GUID                       = "GUID";

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	

    // 元素基类
	class _TDECommonExport Element : public FunctionItemManager, 
		public Object
	{
		friend class ElementManager;
	protected:
		Element(const String& name);
		Element(const String& name,const String& guid);
		virtual ~Element();
	public:
		// 取得显示名称
	    virtual const String& getDisplayName(void) const;
	    virtual void setDisplayName(const String& dispName);

		// 从DataElement载入
		virtual bool load(DataElementPtr& element);
		// 保存到DataElement
		virtual bool save(DataElementPtr& element);

		// 取所在容器
		virtual Container* getParentContainer(void) const;

		// 内部调用
		virtual void _notifyAttached(Container* parent);

		// 是否在容器中
		virtual bool isAttached(void) const;
		
		// 设创建器
		virtual void setCreator(void* creator);

		// 创建器
		virtual void* getCreator(void) const;
		
		// 派生类必须后调用基类setVisible
		virtual void setVisible(bool visible);
		virtual bool isVisible(void) const;	

		// 选择
		virtual void select(bool select = true);
		virtual bool isSelected(void) const;

		// 冻结
		virtual void freeze(bool freeze);
		virtual bool isFrozen(void) const;
		// 锁定	
		virtual void lock(bool lock);
		virtual bool isLocked(void) const;

		// 命令映射 - 继承FunctionItemManager
		virtual void onExecute(const String& name, WPARAM wParam, LPARAM lParam);
		virtual void registerFunctions(void);
		
		// 双击
		virtual void onDbClick(void) { };
		// 属性对话框
		virtual void onPropertyDialog(void) { };

		// 支持挂接自定义对象
		virtual void setUserObject(UserDefinedObject* obj) { mUserObject = obj; }
        virtual UserDefinedObject* getUserObject(void) { return mUserObject; }
		
		virtual void setScale(Real x,Real y,Real z);
		virtual void setPosition(Real x,Real y,Real z);

		// 销毁
		virtual void destroy(void);

	protected:
	    // 初始化完调用该函数
		virtual void onCreate(void);
	private:
		Container* mParentContainer;
		bool mVisible;
		bool mSelected;
		bool mFrozen;
		bool mLocked;
		UserDefinedObject* mUserObject;		
		String mDisplayName;
		void* mCreator;
	};

	///////////////////////////////////////////////////////////////////////////////////////////////

    // 数据层基类
	class _TDECommonExport Container : public FunctionItemManager, 
	    public Object
	{
	public:
		// 数据层发生事件时调用
		class _TDECommonExport Listener
		{
		public:
			Listener() {}
			virtual ~Listener() {}
			
			// 数据层被销毁
			virtual void containerDestroyed(const Container* container) {};

			// 数据层被attach
			virtual void containerAttached(const Container* container) {};
			
			// 数据层被detach
			virtual void containerDetached(const Container* container) {};
		};
		friend class ContainerManager;
	public:
		Container(const String& name, const TDEGUID& guid);		
		virtual ~Container();

		// 取得显示名称
		virtual const String& getDisplayName(void) const;
		virtual void setDisplayName(const String& dispName);

		// 可见性cascade->是否迭代
		// 派生类必须后调用基类setVisible
		virtual void setVisible(bool visible, bool cascade = true);
		virtual bool isVisible(void) const;
		// 逆反可见性
		virtual void flipVisibility(bool cascade = true);
		// 选择
		virtual void select(bool select, bool cascade = true);
		virtual bool isSelected(void) const;
		// 反选
		virtual void flipSelect(bool cascade = true);
		// 冻结
		virtual void freeze(bool freeze, bool cascade = true);
		virtual bool isFrozen(void) const;
		// 锁定	
		virtual void lock(bool lock, bool cascade = true);
		virtual bool isLocked(void) const;

		// 从DataElement载入
		virtual bool load(DataElementPtr& element);
		// 保存到DataElement
		virtual bool save(DataElementPtr& element);

		// UI操作中的双击
		virtual void onDbClick() { };
		// 属性对话框
		virtual void onPropertyDialog() { };
	
		// 命令映射 - 继承FunctionItemManager
		// 如果要基类函数onCommand,请在函数最后调用Container::onCommand()		
		virtual void onExecute(const String& name, WPARAM wParam, LPARAM lParam);		
		virtual void registerFunctions(void);	

		typedef HashMap<String, Container*> ChildContainerMap;
        typedef MapIterator<ChildContainerMap> ChildContainerIterator;
		typedef ConstMapIterator<ChildContainerMap> ConstChildContainerIterator;

		// 设置创建数据层的管理器指针
		ContainerManager* getCreator(void) const;
		void setCreator(ContainerManager* manager); 

		// 以下函数维护数据层之间层次关系
		// 设置父数据层
		virtual void setParent(Container* parent);		
		virtual Container* getParent(void) const;

		// 创建数据层 - 如果不传名称 则内部自动生成
        virtual Container* createChild(const TDEGUID& guid);

        // 创建数据层 - 则内部自动生成
        virtual Container* createChild(const String& name, const TDEGUID& guid);

        // 添加(已经创建的)数据层, 如果这个数据层attach到其他数据层,必须先detach
        virtual void addChild(Container* child);

        // 获得数据层个数
        virtual unsigned short getNumChildren(void) const;

        // 根据索引号得到数据层指针
        virtual Container* getChild(unsigned short index) const;    

		// 根据名词得到数据层指针
        virtual Container* getChild(const String& name) const;

        // 移除所有子数据层
        virtual void removeAllChild(bool bDestroy=0);
		//移除一个孩子节点及其所有子孙节点
        virtual void removeAllChild(Container* child, bool bDestroy=0);

        // 数据层迭代器
        virtual ChildContainerIterator getChildIterator(void);
		virtual ConstChildContainerIterator getChildIterator(void) const;

		// 判断是否在数据层树中
		virtual bool isInGraph(void) const { return mIsInGraph; }		

		// 内部方法,设置是否在数据层树中,在setParent的时候调用
		void setInGraph(bool inGraph);		

		// 该数据层为根数据层,只有数据层管理器能调用该函数		
		virtual void _notifyRootContainer(void) { mIsInGraph = true; }
		
		// 以下函数维护数据层元素
		typedef HashMap<String, Element*> ElementMap;
	    typedef MapIterator<ElementMap> ObjectIterator;
		typedef ConstMapIterator<ElementMap> ConstObjectIterator;

		// 创建元素
		virtual Element* createAttachedObject(DataElementPtr& element);
	
		// 添加元素
		virtual void attachObject(Element* element);

		// 获取元素指针
		virtual Element* getAttachedObject(size_t index);

		// 获取元素指针
		virtual Element* getAttachedObject(const String& name);

		// 获取元素个数
		virtual const size_t getNumAttachedObjects(void) const;	
		
		// 删除元素
		virtual void detachObject(Element* element, bool bDestroy=0);
		// 删除所有元素
		virtual void detachAllObjects(bool bDestroy=0);

		 // 元素迭代器
        virtual ObjectIterator getAttachedObjectIterator(void);
		virtual ConstObjectIterator getAttachedObjectIterator(void) const;

		// 设置层监听器
		void setListener(Listener* listener) { mListener = listener; }		
		// 取层监听器
		Listener* getListener(void) const { return mListener; }

		// 判断是否支持该类型的数据层
		bool checkChildTypeSupported(const TDEGUID& guid);
		// 判断是否支持该类型的元素
		bool checkElementTypeSupported(const TDEGUID& guid);

		// 将Container中的所有内容合并到当前Container
		// 并删除Container内部的Container和元素,但不删除Container
		bool merge(Container* container);

		// 允许被监听
		void setListeningEnabled(bool enabled);

		// 是否允许被监听
		bool getListeningEnabled(void) const;

		//是否在树上将元素节点列出
		bool setChildInTreeListFlag(bool bList = true);

		virtual void setScale(Real x,Real y,Real z);
		virtual void setPosition(Real x,Real y,Real z);

		//是否展开元素
		virtual bool ExpandElement(bool bExpand);

		//设置节点的显示比例
		virtual void getScale(Real& x,Real& y,Real& z);
		long SetDispScale();

	protected:
		// 初始化完调用该函数
		virtual void onCreate(void);

		// 销毁完调用该函数
		virtual void onDestroy(void);

		// 创建数据层的内部实现 如果包含数据层, 必须实现该函数
        virtual Container* createChildImpl(const TDEGUID& guid);

        // 创建数据层的内部实现 如果包含数据层, 必须实现该函数
        virtual Container* createChildImpl(const String& name, const TDEGUID& guid);

		// 创建元素的内部实现 如果包含元素的创建, 必须实现该函数
		virtual Element* createAttachedObjectImpl(DataElementPtr& element);

		// 移除数据层(并不删除),该数据层可以重新attach到别的数据层
        virtual Container* removeChild(Container* child, bool bDestroy=0);
		
	private:
		// 载入数据层 - 被load调用
		bool loadChildren(DataElementPtr& element);
		bool loadElements(DataElementPtr& element);
		
		// 保存元素 - 被save调用
		bool saveChildren(DataElementPtr& element);
		bool saveElements(DataElementPtr& element);
		
		void setChildIndex(Container *pcontainer,BOOL bAdd = TRUE);
		void setObjectIndex(Element *pelement,BOOL bAdd = TRUE);
	
	protected:
		// 元素指针列表
		ElementMap mElementsByName;	
//	private:
		// 指向父亲数据层的指针
        Container* mParent;
		// 创建者
		ContainerManager* mCreator;
		// 直接数据层指针列表
        ChildContainerMap mChildren;
     	// 可见性
		bool mVisible;
		// 是否选择
		bool mSelected;
		// 是否冻结
		bool mFrozen;
		// 是否锁定
		bool mLocked;
		// 是否在数据层树中
		bool mIsInGraph;
		// 显示名
		String mDisplayName;		
		// 只支持一个
		Listener* mListener;
		//是否允许被监听
		bool mEnabled;

		bool mbChildInTreeListFlag;
	};    

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
	// 容器的功能说明信息	
	struct ContainerFunction
	{
		String name;
		String desc;
		String res1;
		String res2;
	};

	// 生成层元素对象的类工厂基类
	class _TDECommonExport ElementFactory : public FactoryObj<Element>   
	{
	public:
		ElementFactory();
		virtual ~ElementFactory();

		// 说明信息
		virtual const ContainerFunction& getContainerFunction(void) { 
			return mContainerFunction; };

	protected:
		ContainerFunction mContainerFunction;
	};

	class _TDECommonExport ContainerSupportFilter : public PtrMapManager<TDEGUID, Object>
	{
	public:
		enum ContainerSupportType
		{
			LST_None = 0,			// 所有都不支持
			LST_List = 1,			// 支持列表
			LST_All = 2,			// 支持所有
			LST_FORCE_DWORD = 0x7fffFFFF,
		};
	public:
		ContainerSupportFilter();
		~ContainerSupportFilter();
		
		void setContainerSupportType(ContainerSupportType type);
		ContainerSupportType getContainerSupportType(void);

		/*
		判断是否支持某种类型
		如果mType == LST_None 返回false
            mType == LST_All  返回true
			mType == LST_List 如果List中存在, 则返回true, 否则返回false
		*/
		bool isSupport(const TDEGUID& guid);	
	protected:		
		ContainerSupportType mType;		
	};

	// 生成层类对象的类工厂基类
	class _TDECommonExport ContainerFactory : public FactoryObj<Container>	
	{
	public:
		ContainerFactory();
		virtual ~ContainerFactory();

		// 说明信息	
		virtual const ContainerFunction& getContainerFunction(void) { 
			return mContainerFunction; };

		// 子容器类型支持信息
		virtual const ContainerSupportFilter* getContainerChildSupportFilter(void) { 
			return &mChildSupportFilter; }

		// 容器元素类型支持信息
		virtual const ContainerSupportFilter* getElementSupportFilter(void) { 
			return &mElementSupportFilter; }

		// 判断子容器类型是否支持
		bool isSupportContainerChildType(const TDEGUID& guid) {
			return mChildSupportFilter.isSupport(guid);
		}

		// 判断容器元素类型是否支持
		bool isSupportElementType(const TDEGUID& guid) {
			return mElementSupportFilter.isSupport(guid);
		}

		// 自定义对象
		virtual void setUserObject(UserDefinedObject* obj) { mUserObject = obj; }
        virtual UserDefinedObject* getUserObject(void) { return mUserObject; }

	protected:
		ContainerFunction mContainerFunction;
		ContainerSupportFilter mChildSupportFilter;
		ContainerSupportFilter mElementSupportFilter;
		UserDefinedObject* mUserObject;
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////

		class GEO2D_BASE_LAYER_EXPORT CGeo2DBaseElement :public Element , public CMessageListenerBase
		{
		public:	
			CGeo2DBaseElement(const String& name);
			virtual	~CGeo2DBaseElement();
		public:
			//删除并销毁节点指针
			virtual long DelteElement(BOOL bPrompt = TRUE);
			//命令映射
			virtual void DoCommand(UINT nID, WPARAM wParam, LPARAM lParam);
			virtual void onExecute(const String& name, WPARAM wParam, LPARAM lParam);
			virtual void registerFunctions(void);
			//加载/保存元素
			virtual bool load(DataElementPtr& element);
			virtual bool save(DataElementPtr& element);
				//关联数据/删除关联
			virtual long ReltElement();
			virtual long ReltElement(char *pFilePath);
			virtual long BeforeDelRelt();
			virtual long DelRelt();
			virtual long DispElement(MyDC mdc);

			virtual long	OnNotifyMessage(long nMsg, WPARAM wParam, LPARAM lParam) ;	
		};

		class  GEO2D_BASE_LAYER_EXPORT CGeo2DBaseLayer : public Container , public CMessageListenerBase
		{
		public:
			CGeo2DBaseLayer(const String& name, const TDEGUID& guid);
			virtual ~CGeo2DBaseLayer();	
		public:
			//添加/删除图层
			virtual long AddLayer();
			virtual long BeforeAddLayer();
			virtual long BeforeDelLayer();
			virtual long DelLayer(BOOL bPrompt = TRUE);
			//添加元素
			virtual long AddElement();
			virtual long BeforeAddElement();
			virtual long BeforeDelElement(CGeo2DBaseElement * pElememt);
			virtual long DelElement(CGeo2DBaseElement * pElememt,BOOL bPrompt = TRUE);
			//关联数据/删除关联
			virtual long ReltLayer();
			virtual long ReltLayer(char *pFilePath);
			virtual long BeforeDelRelt();
			virtual long DelRelt();
	
			virtual bool load(DataElementPtr& element);
			virtual bool save(DataElementPtr& element);
			//命令映射
			virtual void onExecute(const String& name, WPARAM wParam, LPARAM lParam);
			virtual void registerFunctions(void);

			virtual long	OnNotifyMessage(long nMsg, WPARAM wParam, LPARAM lParam) ;	
		protected:
			virtual Element* createAttachedObjectImpl(DataElementPtr& element);
		};


		class _TDECommonExport ElementManager : public ProductManager<Element, 
		ElementFactory>
	{
	public:
		ElementManager();
		virtual ~ElementManager();
		
		// 重载基类函数,加入了功能注册
		Element* create(const String& name, const TDEGUID& guid);
	};

	///////////////////////////////////////////////////////////////////////////////////

		CGeo2DEntityLayerFactory()
	{
		TDEObject	*pObject = NULL;
		mChildSupportFilter.setContainerSupportType(ContainerSupportFilter::LST_List);
		mElementSupportFilter.setContainerSupportType(ContainerSupportFilter::LST_List);
		mElementSupportFilter.create(GEO_ENTITY_ELM_GUID);
		mChildSupportFilter.create(GEO_ENTITY_LAYER_GUID);
		
		pObject	= mElementSupportFilter.get(GEO_ENTITY_ELM_GUID);
		if(pObject)
		{
			pObject->setClassName(GEO_ENTITY_ELM_GUID);
			pObject->setDescription("Mapgis地理实体");
			pObject->setGUID(GEO_ENTITY_ELM_GUID);
			pObject->setHandle(GEO_ENTITY_ELM_GUID);
			pObject->setName("Mapgis地理实体");
		}
		pObject	=	mChildSupportFilter.get(GEO_ENTITY_LAYER_GUID);
		if(pObject)
		{
			pObject->setClassName(GEO_ENTITY_LAYER_GUID);
			pObject->setDescription("二维地理实体图层");
			pObject->setGUID(GEO_ENTITY_LAYER_GUID);
			pObject->setHandle(GEO_ENTITY_LAYER_GUID);
			pObject->setName("二维地理实体图层");
		}
	}


		// 产品管理器
	template<class TProduct, class TFactory>	
	class ProductManager
	{
    public:
		typedef std::map<String, TProduct*> ProductList;
		typedef MapIterator<ProductList> ProductIterator;
		
		typedef std::map<TDEGUID, TFactory*> FactoryList;
		typedef MapIterator<FactoryList> FactoryIterator;

	public:
		ProductManager()
		{
		}

		virtual ~ProductManager()
		{
			destroyAll();
		}		
		// 添加产品工厂		
		virtual void addFactory(TFactory* pFactory)
		{
			TDEGUID guid = pFactory->getType();
			FactoryList::iterator it = mFactories.find(guid);
			if (it != mFactories.end())
			{
				// Factory not found
				G3D_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, "Cannot find an Product factory "
					" to deal with product" + guid, "ProductManager::addProductFactory");
			}
			
			mFactories[pFactory->getType()] = pFactory;		
		}

		// 获取产品工厂
		TFactory* getFactory(const TDEGUID& guid)
		{
			// 检索工厂
			// 查找对应的类工厂
			FactoryList::iterator it = mFactories.find(guid);
			if (it == mFactories.end())
			{
				// Factory not found
				G3D_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, "Cannot find an Product factory "
					" to deal with Product" + guid, "ProductManager::createProduct");
				//return 0;
			} 
			return it->second;			
		}
		
		// 获取产品工厂迭代器
		FactoryIterator getFactoryIterator(void){
			return FactoryIterator(mFactories.begin(), mFactories.end());
		}

		// 创建（生产）产品
		// 参数: name: 工具名称 type: 产品类型
		TProduct* create(const TDEGUID& guid)
		{
			static unsigned long  s_NextGeneratedNameExt = 0;

			// Generate a name
			StringUtil::StrStreamType str;
			str << "Unnamed_" << s_NextGeneratedNameExt++;
			String name = str.str();
			return create(name, guid);		
		}
		
		// 创建（生产）产品
		// 参数: name: 工具名称 type: 产品类型
		virtual TProduct* create(const String& name, 
			const TDEGUID& guid)
		{	
			ProductList::iterator i = mProducts.find(name);
			TProduct* pProduct = 0;
			if (i == mProducts.end())
			{
				// 检索工厂
				// 查找对应的类工厂
				FactoryList::iterator it = mFactories.find(guid);
				if (it == mFactories.end())
				{
					// Factory not found
					G3D_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, "Cannot find an Product factory"
						" to deal with Product" + name, "ProductManager::create");
					//return NULL;
				}
				
				pProduct = it->second->createInstance(name);				
				mProducts[name] = pProduct;				
			}
			else
			{
				pProduct = i->second;
			}			
			return pProduct;
		}
		// 取出对象个数
		virtual const size_t getNum(void) const
		{
			return static_cast<size_t>(mProducts.size());
		}	

		// 产品是否存在
		virtual bool exists(const String& name)
		{
			ProductList::iterator i = mProducts.find(name);
			if (i == mProducts.end())
			{
				return false;
			}
			else
			{
				return true;
			}		 
		}

		// 获取产品
		virtual TProduct* get(const String& name)
		{
			ProductList::iterator i = mProducts.find(name);
			if (i == mProducts.end())
			{
				//Product not found
				G3D_EXCEPT( Exception::ERR_ITEM_NOT_FOUND, 
					"Cannot find Product with name " + name,
					"getProduct");					
				return NULL;
			}
			else
			{
				return i->second;
			}		 
		}
		
		// 获取某类型产品列表
		virtual void getList(ProductList& Products, const TDEGUID& guid)
		{		
			ProductList::iterator i = mProducts.begin();
			for (; i != mProducts.end(); ++i)
			{
				if (i->second->isKindOf(guid))
				{
					Products.insert(ProductList::value_type(i->first, i->second));
				}
			}
		}
		
		// 获取所有产品列表 ~ Fast access to ProductList
		virtual const ProductList& getList(void) const
		{
			return mProducts;
		}
		
		// 销毁产品
		virtual void destroy(TProduct* pProduct)
		{			
			destroy(pProduct->getHandle());
		}
		
		// 销毁产品
		virtual void destroy(const String& name)
		{
			ProductList::iterator i = mProducts.find(name);
			if (i != mProducts.end())
			{
				destroyImpl(name);			
				mProducts.erase(i);
			}			
		}
		
		// 销毁一类产品
		virtual void destroyList(const TDEGUID& guid)
		{
			ProductList::iterator i = mProducts.begin();
			for (; i != mProducts.end(); ++i)
			{
				if (i->second->isKindOf(guid))
				{
					destroyImpl(i->first);
					mProducts.erase(i);
				}
			}
		}		
		// 销毁所有产品
		virtual void destroyAll(void)
		{
			ProductList::iterator i = mProducts.begin();
			for (; i != mProducts.end(); ++i)
			{			
				destroyImpl(i->first);
			}
			mProducts.clear();
		}	

		// 获取产品迭代器		
		ProductIterator getProductIterator(void){
			return ProductIterator(mProducts.begin(), mProducts.end());
		}	
	
	private:
		// 销毁产品 内部调用
		virtual void destroyImpl(const String& name)
		{
			// Find in list
			ProductList::iterator i = mProducts.find(name);		
			if (i != mProducts.end())
			{
				// Find factory to destroy
				FactoryList::iterator fit = mFactories.find(i->second->getClassName());
				if (fit == mFactories.end())
				{
					// Factory not found
					G3D_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, "Cannot find an Product factory "
						"to deal with Product of type " + i->second->getClassName(), "~ProductManager");
				}
				fit->second->destroyInstance(i->second);				
			}
		}	
		
	protected:		
		FactoryList mFactories; // 工厂列表		
		ProductList mProducts; // 产品列表
	};	 

	//CObject ?
	//BOOL isKindOf(const String& strClassName); guid
	//BOOL isA(const String& strClassName);	

	/*
pObject->setClassName(GEO_ENTITY_ELM_GUID);
			pObject->setDescription("Mapgis地理实体");
			pObject->setGUID(GEO_ENTITY_ELM_GUID);
			pObject->setHandle(GEO_ENTITY_ELM_GUID);
			pObject->setName("Mapgis地理实体");
*/

//元素名具有全局的唯一性.

/*
将一下代码保存为ASP文件：
<html>
<head><title>GUID生成器</title></head>
<body>
<blockquote>
<h2 align=center>GUID生成器</h2>
<%
Set MyGuid = Server.CreateObject ("GuidMakr.GUID")
Response.Write (MyGuid.GetGUID)
%>
</blockquote>

</body>
</html>

GUID（读音为 goo-id）即全局唯一标识符，是由确保唯一性的算法生成的一个 128 位（16 字节）的数。该算法来源于开放软件基金会 (OSF) 的分布式计算环境 (DCE)，是关于分布式计算的一套标准。
GUIDs 通常用于唯一地标识 Windows 注册表的入口。例如，Visual Basic 自动生成一个 GUID 来在 Windows 注册表中标识类型库。
Visual Basic 也自动为部件的每一个公共类和接口生成一个 GUID。这些通常称之为类 ID (CLSID) 和接口 ID (IID)。类 ID 和接口 ID 对使用 Visual Basic 开发的部件的版本兼容性是很关键的。
注意   GUIDs 也称为 UUID，即通用唯一标识符。

 在Ogre的overlay中，overlay包括element（元素）和container(容器)二种类型，
 一个overlay中可以没有element，但至少应该有一个container。
 它们都可以是以下三种标准表层元素之一:Panel、BorderPanel、TextArea。 
 其中Panel和BorderPanel一般可以是element或container，而TextArea一般声明为element。

数据插件：必须同时一个元素和一个容器类? 不一定!

场景管理器可以帮助你创建具体的场景节点（Scene Node）。
所谓的场景节点就是你在场景中实际移动变换的基本单元。它们也有自己的关联层次（可以有父节点或者子节点）；

场景中具体的场景内容需要挂接到场景节点上才能显示。这里所说的内容在大多数情况下指的就是实体（Entity）。
如果你有已经有一个的实体的具体实例，你就可以把它绑定到已经存在的场景节点上。

每一个管理器，包括Root（作为“Ogre的控制中心”，所以也可以被称为管理器），
都是作为“单件”对象存在（参考单件设计模式）。创建Root的一个附加功能是帮助你初始了所有Ogre其他管理器对象的实例。

引入类厂的目的：

有很多不同类型的类厂, 再封装类厂管理器。

可以用基类的调用，来完成类对象的createInstance(filename)和destroyInstance

还要考虑：数据元素、容器如何收到消息.

! 容器下面可包括子容器，也可以包括元素; 

容器是否可以看成特殊类型的元素？

CContainerRoot--包含typedef std::list<OverlayContainer*> OverlayContainerList
1) bool AddContainer(OverlayContainer* cont)
2) bool RemoveContainer(OverlayContainer* cont)
3) OverlayContainer *GetContainer(const String& name);
4) void clear();

CElementManager

CElementFactory

CContainer

CElement

CObject

元素和容器是一起管理，还是分开管理? 一起管理，类似于树形结构!

工厂类型，元素名，元素类型-->所属工厂.

一个工厂允许有若干个不同名元素，但工厂对象只有一个!

*/



