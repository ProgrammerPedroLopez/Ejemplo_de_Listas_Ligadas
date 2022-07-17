struct nodo 
{
	int dato;
	nodo* siguiente;
};
struct nodo_d
{
	int dato;
	nodo_d* siguiente;
	nodo_d* anterior;
};
nodo* auxiliar = nullptr;
nodo* raiz = nullptr;

nodo_d* auxiliar_d = nullptr;
nodo_d* raiz_d = nullptr;
 
void agregar_nodo(int);
void agregar_nodo_d(int);

void borrar_nodo(int);
void borrar_nodo_d(int);

void borrar_lista();
void borrar_lista_d();

void cambiar_nodo(int, int);
void cambiar_nodo_d(int, int);

void main() 
{
	borrar_nodo(0);

	agregar_nodo(0);
	agregar_nodo(1);
	agregar_nodo(2);
	agregar_nodo(3);
	agregar_nodo(4);
	agregar_nodo(5);
	agregar_nodo(6);
	
	borrar_nodo(0); 
	borrar_nodo(4);
	borrar_nodo(6);
	borrar_nodo(99);

	cambiar_nodo(3, 12);
	cambiar_nodo(99, 789);

	borrar_lista();

	borrar_nodo_d(0);

	agregar_nodo_d(0);
	agregar_nodo_d(1);
	agregar_nodo_d(2);
	agregar_nodo_d(3);
	agregar_nodo_d(4);
	agregar_nodo_d(5);
	agregar_nodo_d(6);

	borrar_nodo_d(0);
	borrar_nodo_d(4);
	borrar_nodo_d(6);
	borrar_nodo_d(99);

	cambiar_nodo_d(2, 12);
	cambiar_nodo_d(99, 789);

	borrar_lista_d();
}

void agregar_nodo(int param) 
{
	if (raiz == nullptr) 
	{
		raiz = new nodo;
		raiz->dato = param;
		raiz->siguiente = nullptr;
		auxiliar = raiz;
	}
	else 
	{
		auxiliar = raiz;
		while (auxiliar->siguiente != nullptr)
		{
			auxiliar = auxiliar->siguiente;
		}
		auxiliar->siguiente = new nodo;
		auxiliar->siguiente->siguiente = nullptr;
		auxiliar = auxiliar->siguiente;
		auxiliar->dato = param;
	}
}
void borrar_nodo(int param) 
{
	//en caso de que la lista este vacia
	if (raiz == nullptr) 
	{
		return;
	}
	//Si el elemento a borrar es el primer nodo
	auxiliar = raiz;
	if (auxiliar->dato == param) 
	{
		raiz = raiz->siguiente;
		delete auxiliar;
	}
	else 
	{
		//Si el elemento a borrar es algun nodo de en medio
		while (auxiliar->siguiente != nullptr && auxiliar->siguiente->dato != param)
		{
			auxiliar = auxiliar->siguiente;
		}

		if (auxiliar->siguiente != nullptr && auxiliar->siguiente->dato == param)
		{
			nodo* temporal = auxiliar->siguiente;
			auxiliar->siguiente = auxiliar->siguiente->siguiente;
			delete temporal;
		}
	}
}
void borrar_lista() 
{
	auxiliar = raiz;
	while (raiz != nullptr) 
	{
		raiz = auxiliar->siguiente;
		delete auxiliar;
		auxiliar = raiz;
	}
}
void cambiar_nodo(int param, int new_value) 
{
	auxiliar = raiz;
	while (auxiliar != nullptr)
	{
		if (auxiliar->dato == param) 
		{
			auxiliar->dato = new_value;
			break;
		}
		auxiliar = auxiliar->siguiente;
	}
}

void agregar_nodo_d(int param)
{
	if (raiz_d == nullptr)
	{
		raiz_d = new nodo_d;
		raiz_d->dato = param;
		raiz_d->siguiente = nullptr;
		raiz_d->anterior = nullptr;
		auxiliar_d = raiz_d;
	}
	else
	{
		auxiliar_d = raiz_d;
		while (auxiliar_d->siguiente != nullptr)
		{
			auxiliar_d = auxiliar_d->siguiente;
		}
		auxiliar_d->siguiente = new nodo_d;
		auxiliar_d->siguiente->siguiente = nullptr;
		auxiliar_d->siguiente->anterior = auxiliar_d;
		auxiliar_d = auxiliar_d->siguiente;
		auxiliar_d->dato = param;
	}
}
void borrar_nodo_d(int param) 
{
	//en caso de que la lista este vacia
	if (raiz_d == nullptr)
	{
		return;
	}

	//Si el elemento a borrar es el primer nodo
	auxiliar_d = raiz_d;
	if (auxiliar_d->dato == param)
	{
		raiz_d = raiz_d->siguiente;
		raiz_d->anterior = nullptr;
		delete auxiliar_d;
	}
	else
	{
		//Si el elemento a borrar es algun nodo de en medio
		while (auxiliar_d != nullptr && auxiliar_d->dato != param)
		{
			auxiliar_d = auxiliar_d->siguiente;
		}

		if (auxiliar_d != nullptr)
		{
			if (auxiliar_d->dato == param)
			{
				
				nodo_d* temporal = auxiliar_d;
				temporal->anterior->siguiente = temporal->siguiente;
				if (temporal->siguiente != nullptr) //por si es el ultimo de la lista
				{
					temporal->siguiente->anterior = temporal->anterior;
				}
				delete temporal;
			}
		}
		
	}
}
void borrar_lista_d() 
{
	auxiliar_d = raiz_d;
	while (raiz_d != nullptr)
	{
		raiz_d = auxiliar_d->siguiente;
		delete auxiliar_d;
		auxiliar_d = raiz_d;
	}
}
void cambiar_nodo_d(int param, int new_value)
{
	auxiliar_d = raiz_d;
	while (auxiliar_d != nullptr)
	{
		if (auxiliar_d->dato == param)
		{
			auxiliar_d->dato = new_value;
			break;
		}
		auxiliar_d = auxiliar_d->siguiente;
	}
}