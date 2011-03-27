
    // Ԫ�������ַ���
	const String STR_ELEMENT_DELETE				= "ɾ������";
	const String STR_ELEMENT_PROPERTY			= "��ʾ��������";

	// ���ݲ������ַ���
	//----------------------------------------------------------
	const String STR_CONTAINER_SELECT				= "ѡ�����ݲ�";
	const String STR_CONTAINER_UNSELECT				= "ȡ��ѡ��";
	const String STR_CONTAINER_DELETE				= "ɾ�����ݲ�";
	const String STR_CONTAINER_SET_AS_ACTIVE		= "��Ϊ�";	
	//-----------------------------------------------------------
	const String STR_CONTAINER_CREATE_CHILD			= "�������ݲ�";
	const String STR_CONTAINER_ALL_CHILD_VISIBLE	= "��ʾ�������ݲ�";
	const String STR_CONTAINER_ALL_CHILD_INVISIBLE	= "�����������ݲ�";
	const String STR_CONTAINER_DELETE_ALL_CHILDREN	= "ɾ���������ݲ�";	
	const String STR_CONTAINER_DELETE_ALL_ELEMENTS	= "ɾ������Ԫ��";
	const String STR_CONTAINER_EXPAND_ELE	= "չ��Ԫ��";
	const String STR_CONTAINER_UN_EXPAND_ELE	= "����Ԫ��";

	const String STR_CONTAINER_SET_DISP_SCALE	= "������ʾ����";
	

	//-----------------------------------------------------------
	const String STR_CONTAINER_PROPERTY				= "����";

	static String ELEMENT_GUID = "{579FC6DD-B46D-42e9-9879-CCB7139119FA}";

	// {9537542C-9554-4ed8-BA10-7D0270E04C6A}
	const String CONTAINER_GUID = "{ 0x9537542c, 0x9554, 0x4ed8, { 0xba, 0x10, 0x7d, 0x2, 0x70, 0xe0, 0x4c, 0x6a } }";

	// ͼ�������ַ���
		//----------------------------------------------------------
		const String STR_OPEN_LAYER					= "��";
		const String STR_CLOSE_LAYER				= "�ر�";
		const String STR_OPEN_ELEMENT				= "��";
		const String STR_CLOSE_ELEMENT				= "�ر�";
		//----------------------------------------------------------	
		const String STR_ADD_LAYER					= "���ͼ��";
		const String STR_DEL_LAYER					= "ɾ��ͼ��";
		const String STR_ADD_ELEMENT				= "��ӽڵ�";
		const String STR_DEL_ELEMENT				= "ɾ���ڵ�";
		const String STR_RELT_ELEMENT				= "��������";
		const String STR_DEL_RELT					= "ɾ������";	
		
		//-----------------------------------------------------------
		//-----------------------------------------------------------
		const String STR_PROPERTY_LAYER				= "����";
		const String STR_PROPERTY_ELEMENT			= "����";
		const String STR_SEPARATE1					= "�ָ���1";
		const String STR_SEPARATE2					= "�ָ���2";
		//-----------------------------------------------------------
		//-----------------------------------------------------------
		// ELEMENT �����ֶ�����
		const String STR_NAME						= "Name";
		const String STR_CLASSNAME					= "ClassName";
		const String STR_DES						= "Des";
		const String STR_USERDATA					= "UserData";
		const String STR_GUID                       = "GUID";

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	

    // Ԫ�ػ���
	class _TDECommonExport Element : public FunctionItemManager, 
		public Object
	{
		friend class ElementManager;
	protected:
		Element(const String& name);
		Element(const String& name,const String& guid);
		virtual ~Element();
	public:
		// ȡ����ʾ����
	    virtual const String& getDisplayName(void) const;
	    virtual void setDisplayName(const String& dispName);

		// ��DataElement����
		virtual bool load(DataElementPtr& element);
		// ���浽DataElement
		virtual bool save(DataElementPtr& element);

		// ȡ��������
		virtual Container* getParentContainer(void) const;

		// �ڲ�����
		virtual void _notifyAttached(Container* parent);

		// �Ƿ���������
		virtual bool isAttached(void) const;
		
		// �贴����
		virtual void setCreator(void* creator);

		// ������
		virtual void* getCreator(void) const;
		
		// ������������û���setVisible
		virtual void setVisible(bool visible);
		virtual bool isVisible(void) const;	

		// ѡ��
		virtual void select(bool select = true);
		virtual bool isSelected(void) const;

		// ����
		virtual void freeze(bool freeze);
		virtual bool isFrozen(void) const;
		// ����	
		virtual void lock(bool lock);
		virtual bool isLocked(void) const;

		// ����ӳ�� - �̳�FunctionItemManager
		virtual void onExecute(const String& name, WPARAM wParam, LPARAM lParam);
		virtual void registerFunctions(void);
		
		// ˫��
		virtual void onDbClick(void) { };
		// ���ԶԻ���
		virtual void onPropertyDialog(void) { };

		// ֧�ֹҽ��Զ������
		virtual void setUserObject(UserDefinedObject* obj) { mUserObject = obj; }
        virtual UserDefinedObject* getUserObject(void) { return mUserObject; }
		
		virtual void setScale(Real x,Real y,Real z);
		virtual void setPosition(Real x,Real y,Real z);

		// ����
		virtual void destroy(void);

	protected:
	    // ��ʼ������øú���
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

    // ���ݲ����
	class _TDECommonExport Container : public FunctionItemManager, 
	    public Object
	{
	public:
		// ���ݲ㷢���¼�ʱ����
		class _TDECommonExport Listener
		{
		public:
			Listener() {}
			virtual ~Listener() {}
			
			// ���ݲ㱻����
			virtual void containerDestroyed(const Container* container) {};

			// ���ݲ㱻attach
			virtual void containerAttached(const Container* container) {};
			
			// ���ݲ㱻detach
			virtual void containerDetached(const Container* container) {};
		};
		friend class ContainerManager;
	public:
		Container(const String& name, const TDEGUID& guid);		
		virtual ~Container();

		// ȡ����ʾ����
		virtual const String& getDisplayName(void) const;
		virtual void setDisplayName(const String& dispName);

		// �ɼ���cascade->�Ƿ����
		// ������������û���setVisible
		virtual void setVisible(bool visible, bool cascade = true);
		virtual bool isVisible(void) const;
		// �淴�ɼ���
		virtual void flipVisibility(bool cascade = true);
		// ѡ��
		virtual void select(bool select, bool cascade = true);
		virtual bool isSelected(void) const;
		// ��ѡ
		virtual void flipSelect(bool cascade = true);
		// ����
		virtual void freeze(bool freeze, bool cascade = true);
		virtual bool isFrozen(void) const;
		// ����	
		virtual void lock(bool lock, bool cascade = true);
		virtual bool isLocked(void) const;

		// ��DataElement����
		virtual bool load(DataElementPtr& element);
		// ���浽DataElement
		virtual bool save(DataElementPtr& element);

		// UI�����е�˫��
		virtual void onDbClick() { };
		// ���ԶԻ���
		virtual void onPropertyDialog() { };
	
		// ����ӳ�� - �̳�FunctionItemManager
		// ���Ҫ���ຯ��onCommand,���ں���������Container::onCommand()		
		virtual void onExecute(const String& name, WPARAM wParam, LPARAM lParam);		
		virtual void registerFunctions(void);	

		typedef HashMap<String, Container*> ChildContainerMap;
        typedef MapIterator<ChildContainerMap> ChildContainerIterator;
		typedef ConstMapIterator<ChildContainerMap> ConstChildContainerIterator;

		// ���ô������ݲ�Ĺ�����ָ��
		ContainerManager* getCreator(void) const;
		void setCreator(ContainerManager* manager); 

		// ���º���ά�����ݲ�֮���ι�ϵ
		// ���ø����ݲ�
		virtual void setParent(Container* parent);		
		virtual Container* getParent(void) const;

		// �������ݲ� - ����������� ���ڲ��Զ�����
        virtual Container* createChild(const TDEGUID& guid);

        // �������ݲ� - ���ڲ��Զ�����
        virtual Container* createChild(const String& name, const TDEGUID& guid);

        // ���(�Ѿ�������)���ݲ�, ���������ݲ�attach���������ݲ�,������detach
        virtual void addChild(Container* child);

        // ������ݲ����
        virtual unsigned short getNumChildren(void) const;

        // ���������ŵõ����ݲ�ָ��
        virtual Container* getChild(unsigned short index) const;    

		// �������ʵõ����ݲ�ָ��
        virtual Container* getChild(const String& name) const;

        // �Ƴ����������ݲ�
        virtual void removeAllChild(bool bDestroy=0);
		//�Ƴ�һ�����ӽڵ㼰����������ڵ�
        virtual void removeAllChild(Container* child, bool bDestroy=0);

        // ���ݲ������
        virtual ChildContainerIterator getChildIterator(void);
		virtual ConstChildContainerIterator getChildIterator(void) const;

		// �ж��Ƿ������ݲ�����
		virtual bool isInGraph(void) const { return mIsInGraph; }		

		// �ڲ�����,�����Ƿ������ݲ�����,��setParent��ʱ�����
		void setInGraph(bool inGraph);		

		// �����ݲ�Ϊ�����ݲ�,ֻ�����ݲ�������ܵ��øú���		
		virtual void _notifyRootContainer(void) { mIsInGraph = true; }
		
		// ���º���ά�����ݲ�Ԫ��
		typedef HashMap<String, Element*> ElementMap;
	    typedef MapIterator<ElementMap> ObjectIterator;
		typedef ConstMapIterator<ElementMap> ConstObjectIterator;

		// ����Ԫ��
		virtual Element* createAttachedObject(DataElementPtr& element);
	
		// ���Ԫ��
		virtual void attachObject(Element* element);

		// ��ȡԪ��ָ��
		virtual Element* getAttachedObject(size_t index);

		// ��ȡԪ��ָ��
		virtual Element* getAttachedObject(const String& name);

		// ��ȡԪ�ظ���
		virtual const size_t getNumAttachedObjects(void) const;	
		
		// ɾ��Ԫ��
		virtual void detachObject(Element* element, bool bDestroy=0);
		// ɾ������Ԫ��
		virtual void detachAllObjects(bool bDestroy=0);

		 // Ԫ�ص�����
        virtual ObjectIterator getAttachedObjectIterator(void);
		virtual ConstObjectIterator getAttachedObjectIterator(void) const;

		// ���ò������
		void setListener(Listener* listener) { mListener = listener; }		
		// ȡ�������
		Listener* getListener(void) const { return mListener; }

		// �ж��Ƿ�֧�ָ����͵����ݲ�
		bool checkChildTypeSupported(const TDEGUID& guid);
		// �ж��Ƿ�֧�ָ����͵�Ԫ��
		bool checkElementTypeSupported(const TDEGUID& guid);

		// ��Container�е��������ݺϲ�����ǰContainer
		// ��ɾ��Container�ڲ���Container��Ԫ��,����ɾ��Container
		bool merge(Container* container);

		// ��������
		void setListeningEnabled(bool enabled);

		// �Ƿ���������
		bool getListeningEnabled(void) const;

		//�Ƿ������Ͻ�Ԫ�ؽڵ��г�
		bool setChildInTreeListFlag(bool bList = true);

		virtual void setScale(Real x,Real y,Real z);
		virtual void setPosition(Real x,Real y,Real z);

		//�Ƿ�չ��Ԫ��
		virtual bool ExpandElement(bool bExpand);

		//���ýڵ����ʾ����
		virtual void getScale(Real& x,Real& y,Real& z);
		long SetDispScale();

	protected:
		// ��ʼ������øú���
		virtual void onCreate(void);

		// ��������øú���
		virtual void onDestroy(void);

		// �������ݲ���ڲ�ʵ�� ����������ݲ�, ����ʵ�ָú���
        virtual Container* createChildImpl(const TDEGUID& guid);

        // �������ݲ���ڲ�ʵ�� ����������ݲ�, ����ʵ�ָú���
        virtual Container* createChildImpl(const String& name, const TDEGUID& guid);

		// ����Ԫ�ص��ڲ�ʵ�� �������Ԫ�صĴ���, ����ʵ�ָú���
		virtual Element* createAttachedObjectImpl(DataElementPtr& element);

		// �Ƴ����ݲ�(����ɾ��),�����ݲ��������attach��������ݲ�
        virtual Container* removeChild(Container* child, bool bDestroy=0);
		
	private:
		// �������ݲ� - ��load����
		bool loadChildren(DataElementPtr& element);
		bool loadElements(DataElementPtr& element);
		
		// ����Ԫ�� - ��save����
		bool saveChildren(DataElementPtr& element);
		bool saveElements(DataElementPtr& element);
		
		void setChildIndex(Container *pcontainer,BOOL bAdd = TRUE);
		void setObjectIndex(Element *pelement,BOOL bAdd = TRUE);
	
	protected:
		// Ԫ��ָ���б�
		ElementMap mElementsByName;	
//	private:
		// ָ�������ݲ��ָ��
        Container* mParent;
		// ������
		ContainerManager* mCreator;
		// ֱ�����ݲ�ָ���б�
        ChildContainerMap mChildren;
     	// �ɼ���
		bool mVisible;
		// �Ƿ�ѡ��
		bool mSelected;
		// �Ƿ񶳽�
		bool mFrozen;
		// �Ƿ�����
		bool mLocked;
		// �Ƿ������ݲ�����
		bool mIsInGraph;
		// ��ʾ��
		String mDisplayName;		
		// ֻ֧��һ��
		Listener* mListener;
		//�Ƿ���������
		bool mEnabled;

		bool mbChildInTreeListFlag;
	};    

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
	// �����Ĺ���˵����Ϣ	
	struct ContainerFunction
	{
		String name;
		String desc;
		String res1;
		String res2;
	};

	// ���ɲ�Ԫ�ض�����๤������
	class _TDECommonExport ElementFactory : public FactoryObj<Element>   
	{
	public:
		ElementFactory();
		virtual ~ElementFactory();

		// ˵����Ϣ
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
			LST_None = 0,			// ���ж���֧��
			LST_List = 1,			// ֧���б�
			LST_All = 2,			// ֧������
			LST_FORCE_DWORD = 0x7fffFFFF,
		};
	public:
		ContainerSupportFilter();
		~ContainerSupportFilter();
		
		void setContainerSupportType(ContainerSupportType type);
		ContainerSupportType getContainerSupportType(void);

		/*
		�ж��Ƿ�֧��ĳ������
		���mType == LST_None ����false
            mType == LST_All  ����true
			mType == LST_List ���List�д���, �򷵻�true, ���򷵻�false
		*/
		bool isSupport(const TDEGUID& guid);	
	protected:		
		ContainerSupportType mType;		
	};

	// ���ɲ��������๤������
	class _TDECommonExport ContainerFactory : public FactoryObj<Container>	
	{
	public:
		ContainerFactory();
		virtual ~ContainerFactory();

		// ˵����Ϣ	
		virtual const ContainerFunction& getContainerFunction(void) { 
			return mContainerFunction; };

		// ����������֧����Ϣ
		virtual const ContainerSupportFilter* getContainerChildSupportFilter(void) { 
			return &mChildSupportFilter; }

		// ����Ԫ������֧����Ϣ
		virtual const ContainerSupportFilter* getElementSupportFilter(void) { 
			return &mElementSupportFilter; }

		// �ж������������Ƿ�֧��
		bool isSupportContainerChildType(const TDEGUID& guid) {
			return mChildSupportFilter.isSupport(guid);
		}

		// �ж�����Ԫ�������Ƿ�֧��
		bool isSupportElementType(const TDEGUID& guid) {
			return mElementSupportFilter.isSupport(guid);
		}

		// �Զ������
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
			//ɾ�������ٽڵ�ָ��
			virtual long DelteElement(BOOL bPrompt = TRUE);
			//����ӳ��
			virtual void DoCommand(UINT nID, WPARAM wParam, LPARAM lParam);
			virtual void onExecute(const String& name, WPARAM wParam, LPARAM lParam);
			virtual void registerFunctions(void);
			//����/����Ԫ��
			virtual bool load(DataElementPtr& element);
			virtual bool save(DataElementPtr& element);
				//��������/ɾ������
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
			//���/ɾ��ͼ��
			virtual long AddLayer();
			virtual long BeforeAddLayer();
			virtual long BeforeDelLayer();
			virtual long DelLayer(BOOL bPrompt = TRUE);
			//���Ԫ��
			virtual long AddElement();
			virtual long BeforeAddElement();
			virtual long BeforeDelElement(CGeo2DBaseElement * pElememt);
			virtual long DelElement(CGeo2DBaseElement * pElememt,BOOL bPrompt = TRUE);
			//��������/ɾ������
			virtual long ReltLayer();
			virtual long ReltLayer(char *pFilePath);
			virtual long BeforeDelRelt();
			virtual long DelRelt();
	
			virtual bool load(DataElementPtr& element);
			virtual bool save(DataElementPtr& element);
			//����ӳ��
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
		
		// ���ػ��ຯ��,�����˹���ע��
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
			pObject->setDescription("Mapgis����ʵ��");
			pObject->setGUID(GEO_ENTITY_ELM_GUID);
			pObject->setHandle(GEO_ENTITY_ELM_GUID);
			pObject->setName("Mapgis����ʵ��");
		}
		pObject	=	mChildSupportFilter.get(GEO_ENTITY_LAYER_GUID);
		if(pObject)
		{
			pObject->setClassName(GEO_ENTITY_LAYER_GUID);
			pObject->setDescription("��ά����ʵ��ͼ��");
			pObject->setGUID(GEO_ENTITY_LAYER_GUID);
			pObject->setHandle(GEO_ENTITY_LAYER_GUID);
			pObject->setName("��ά����ʵ��ͼ��");
		}
	}


		// ��Ʒ������
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
		// ��Ӳ�Ʒ����		
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

		// ��ȡ��Ʒ����
		TFactory* getFactory(const TDEGUID& guid)
		{
			// ��������
			// ���Ҷ�Ӧ���๤��
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
		
		// ��ȡ��Ʒ����������
		FactoryIterator getFactoryIterator(void){
			return FactoryIterator(mFactories.begin(), mFactories.end());
		}

		// ��������������Ʒ
		// ����: name: �������� type: ��Ʒ����
		TProduct* create(const TDEGUID& guid)
		{
			static unsigned long  s_NextGeneratedNameExt = 0;

			// Generate a name
			StringUtil::StrStreamType str;
			str << "Unnamed_" << s_NextGeneratedNameExt++;
			String name = str.str();
			return create(name, guid);		
		}
		
		// ��������������Ʒ
		// ����: name: �������� type: ��Ʒ����
		virtual TProduct* create(const String& name, 
			const TDEGUID& guid)
		{	
			ProductList::iterator i = mProducts.find(name);
			TProduct* pProduct = 0;
			if (i == mProducts.end())
			{
				// ��������
				// ���Ҷ�Ӧ���๤��
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
		// ȡ���������
		virtual const size_t getNum(void) const
		{
			return static_cast<size_t>(mProducts.size());
		}	

		// ��Ʒ�Ƿ����
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

		// ��ȡ��Ʒ
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
		
		// ��ȡĳ���Ͳ�Ʒ�б�
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
		
		// ��ȡ���в�Ʒ�б� ~ Fast access to ProductList
		virtual const ProductList& getList(void) const
		{
			return mProducts;
		}
		
		// ���ٲ�Ʒ
		virtual void destroy(TProduct* pProduct)
		{			
			destroy(pProduct->getHandle());
		}
		
		// ���ٲ�Ʒ
		virtual void destroy(const String& name)
		{
			ProductList::iterator i = mProducts.find(name);
			if (i != mProducts.end())
			{
				destroyImpl(name);			
				mProducts.erase(i);
			}			
		}
		
		// ����һ���Ʒ
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
		// �������в�Ʒ
		virtual void destroyAll(void)
		{
			ProductList::iterator i = mProducts.begin();
			for (; i != mProducts.end(); ++i)
			{			
				destroyImpl(i->first);
			}
			mProducts.clear();
		}	

		// ��ȡ��Ʒ������		
		ProductIterator getProductIterator(void){
			return ProductIterator(mProducts.begin(), mProducts.end());
		}	
	
	private:
		// ���ٲ�Ʒ �ڲ�����
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
		FactoryList mFactories; // �����б�		
		ProductList mProducts; // ��Ʒ�б�
	};	 

	//CObject ?
	//BOOL isKindOf(const String& strClassName); guid
	//BOOL isA(const String& strClassName);	

	/*
pObject->setClassName(GEO_ENTITY_ELM_GUID);
			pObject->setDescription("Mapgis����ʵ��");
			pObject->setGUID(GEO_ENTITY_ELM_GUID);
			pObject->setHandle(GEO_ENTITY_ELM_GUID);
			pObject->setName("Mapgis����ʵ��");
*/

//Ԫ��������ȫ�ֵ�Ψһ��.

/*
��һ�´��뱣��ΪASP�ļ���
<html>
<head><title>GUID������</title></head>
<body>
<blockquote>
<h2 align=center>GUID������</h2>
<%
Set MyGuid = Server.CreateObject ("GuidMakr.GUID")
Response.Write (MyGuid.GetGUID)
%>
</blockquote>

</body>
</html>

GUID������Ϊ goo-id����ȫ��Ψһ��ʶ��������ȷ��Ψһ�Ե��㷨���ɵ�һ�� 128 λ��16 �ֽڣ����������㷨��Դ�ڿ����������� (OSF) �ķֲ�ʽ���㻷�� (DCE)���ǹ��ڷֲ�ʽ�����һ�ױ�׼��
GUIDs ͨ������Ψһ�ر�ʶ Windows ע������ڡ����磬Visual Basic �Զ�����һ�� GUID ���� Windows ע����б�ʶ���Ϳ⡣
Visual Basic Ҳ�Զ�Ϊ������ÿһ��������ͽӿ�����һ�� GUID����Щͨ����֮Ϊ�� ID (CLSID) �ͽӿ� ID (IID)���� ID �ͽӿ� ID ��ʹ�� Visual Basic �����Ĳ����İ汾�������Ǻܹؼ��ġ�
ע��   GUIDs Ҳ��Ϊ UUID����ͨ��Ψһ��ʶ����

 ��Ogre��overlay�У�overlay����element��Ԫ�أ���container(����)�������ͣ�
 һ��overlay�п���û��element��������Ӧ����һ��container��
 ���Ƕ��������������ֱ�׼���Ԫ��֮һ:Panel��BorderPanel��TextArea�� 
 ����Panel��BorderPanelһ�������element��container����TextAreaһ������Ϊelement��

���ݲ��������ͬʱһ��Ԫ�غ�һ��������? ��һ��!

�������������԰����㴴������ĳ����ڵ㣨Scene Node����
��ν�ĳ����ڵ�������ڳ�����ʵ���ƶ��任�Ļ�����Ԫ������Ҳ���Լ��Ĺ�����Σ������и��ڵ�����ӽڵ㣩��

�����о���ĳ���������Ҫ�ҽӵ������ڵ��ϲ�����ʾ��������˵�������ڴ���������ָ�ľ���ʵ�壨Entity����
��������Ѿ���һ����ʵ��ľ���ʵ������Ϳ��԰����󶨵��Ѿ����ڵĳ����ڵ��ϡ�

ÿһ��������������Root����Ϊ��Ogre�Ŀ������ġ�������Ҳ���Ա���Ϊ����������
������Ϊ��������������ڣ��ο��������ģʽ��������Root��һ�����ӹ����ǰ������ʼ������Ogre���������������ʵ����

�����೧��Ŀ�ģ�

�кܶ಻ͬ���͵��೧, �ٷ�װ�೧��������

�����û���ĵ��ã������������createInstance(filename)��destroyInstance

��Ҫ���ǣ�����Ԫ�ء���������յ���Ϣ.

! ��������ɰ�����������Ҳ���԰���Ԫ��; 

�����Ƿ���Կ����������͵�Ԫ�أ�

CContainerRoot--����typedef std::list<OverlayContainer*> OverlayContainerList
1) bool AddContainer(OverlayContainer* cont)
2) bool RemoveContainer(OverlayContainer* cont)
3) OverlayContainer *GetContainer(const String& name);
4) void clear();

CElementManager

CElementFactory

CContainer

CElement

CObject

Ԫ�غ�������һ��������Ƿֿ�����? һ��������������νṹ!

�������ͣ�Ԫ������Ԫ������-->��������.

һ���������������ɸ���ͬ��Ԫ�أ�����������ֻ��һ��!

*/



