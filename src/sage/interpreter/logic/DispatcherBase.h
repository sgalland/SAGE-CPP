#pragma once

#include <map>
#include <vector>

#include "DispatcherContainer.h"

namespace sage
{
	namespace agi
	{
		template<typename R>
		class DispatcherBase
		{
		protected:
			std::map<uint8_t, DispatcherContainer*> containers;
		public:
			DispatcherBase();
			~DispatcherBase();

			DispatcherContainer* DispatcherBase::operator[](const uint8_t index);

			void InsertMethod(DispatcherContainer* container);
			R ExecuteTest(int id, std::vector<uint8_t> args);
			R ExecuteTest(int id);
			R ExecuteTest(int id, uint8_t arg1);
			R ExecuteTest(int id, uint8_t arg1, uint8_t arg2);
			R ExecuteTest(int id, uint8_t arg1, uint8_t arg2, uint8_t arg3);
			R ExecuteTest(int id, uint8_t arg1, uint8_t arg2, uint8_t arg3, uint8_t arg4);
			R ExecuteTest(int id, uint8_t arg1, uint8_t arg2, uint8_t arg3, uint8_t arg4, uint8_t arg5);

			R ExecuteAction(int id, std::vector<uint8_t> args);
			R ExecuteAction(int id);
			R ExecuteAction(int id, uint8_t arg1);
			R ExecuteAction(int id, uint8_t arg1, uint8_t arg2);
			R ExecuteAction(int id, uint8_t arg1, uint8_t arg2, uint8_t arg3);
			R ExecuteAction(int id, uint8_t arg1, uint8_t arg2, uint8_t arg3, uint8_t arg4);
			R ExecuteAction(int id, uint8_t arg1, uint8_t arg2, uint8_t arg3, uint8_t arg4, uint8_t arg5);
		};
		template<typename R>
		inline DispatcherBase<R>::DispatcherBase()
		{
		}
		template<typename R>
		inline DispatcherBase<R>::~DispatcherBase()
		{
			for (auto item : containers)
			{
				if (item.second != nullptr)
					delete item.second;
			}
		}
		template<typename R>
		inline DispatcherContainer * DispatcherBase<R>::operator[](const uint8_t index)
		{
			if (index > 0 && index < this->containers.size())
				return this->containers.at(index);
			return nullptr;
		}
		template<typename R>
		inline void DispatcherBase<R>::InsertMethod(DispatcherContainer * container)
		{
			this->containers.insert(std::pair<uint8_t, DispatcherContainer*>(container->getID(), container));
		}
		template<typename R>
		inline R DispatcherBase<R>::ExecuteTest(int id, std::vector<uint8_t> args)
		{
			// TODO: expand the vector into vars
			uint8_t arg1, arg2, arg3, arg4, arg5;

			// TODO: this might be a good candidate for either a refactor or rewrite... can this be done simpler?
			switch (this->containers[id]->getArgumentCount())
			{
			case 1:
				arg1 = args.at(0);
				return ExecuteTest(id, arg1);
				break;
			case 2:
				arg1 = args.at(0);
				arg2 = args.at(1);
				return ExecuteTest(id, arg1, arg2);
				break;
			case 3:
				arg1 = args.at(0);
				arg2 = args.at(1);
				arg3 = args.at(2);
				return ExecuteTest(id, arg1, arg2, arg3);
				break;
			case 4:
				arg1 = args.at(0);
				arg2 = args.at(1);
				arg3 = args.at(2);
				arg4 = args.at(3);
				return ExecuteTest(id, arg1, arg2, arg3, arg4);
				break;
			case 5:
				arg1 = args.at(0);
				arg2 = args.at(1);
				arg3 = args.at(2);
				arg4 = args.at(3);
				arg5 = args.at(4);
				return ExecuteTest(id, arg1, arg2, arg3, arg4, arg5);
				break;
			}

			return ExecuteTest(id);
		}
		template<typename R>
		inline R DispatcherBase<R>::ExecuteTest(int id)
		{
			return ExecuteTest(id, 0, 0, 0, 0, 0);
		}
		template<typename R>
		inline R DispatcherBase<R>::ExecuteTest(int id, uint8_t arg1)
		{
			return ExecuteTest(id, arg1, 0, 0, 0, 0);
		}
		template<typename R>
		inline R DispatcherBase<R>::ExecuteTest(int id, uint8_t arg1, uint8_t arg2)
		{
			return ExecuteTest(id, arg1, arg2, 0, 0, 0);
		}
		template<typename R>
		inline R DispatcherBase<R>::ExecuteTest(int id, uint8_t arg1, uint8_t arg2, uint8_t arg3)
		{
			return ExecuteTest(id, arg1, arg2, arg3, 0, 0);
		}
		template<typename R>
		inline R DispatcherBase<R>::ExecuteTest(int id, uint8_t arg1, uint8_t arg2, uint8_t arg3, uint8_t arg4)
		{
			return ExecuteTest(id, arg1, arg2, arg3, arg4, 0);
		}
		template<typename R>
		inline R DispatcherBase<R>::ExecuteTest(int id, uint8_t arg1, uint8_t arg2, uint8_t arg3, uint8_t arg4, uint8_t arg5)
		{
			return this->containers[id]->CallTest(arg1, arg2, arg3, arg4, arg5);
		}




		template<typename R>
		inline R DispatcherBase<R>::ExecuteAction(int id, std::vector<uint8_t> args)
		{
			// TODO: expand the vector into vars
			uint8_t arg1, arg2, arg3, arg4, arg5;

			// TODO: this might be a good candidate for either a refactor or rewrite... can this be done simpler?
			switch (this->containers[id]->getArgumentCount())
			{
			case 1:
				arg1 = args.at(0);
				break;
			case 2:
				arg1 = args.at(0);
				arg2 = args.at(1);
				break;
			case 3:
				arg1 = args.at(0);
				arg2 = args.at(1);
				arg3 = args.at(2);
				break;
			case 4:
				arg1 = args.at(0);
				arg2 = args.at(1);
				arg3 = args.at(2);
				arg4 = args.at(3);
				break;
			case 5:
				arg1 = args.at(0);
				arg2 = args.at(1);
				arg3 = args.at(2);
				arg4 = args.at(3);
				arg5 = args.at(4);
				break;
			}

			switch (this->containers[id]->getArgumentCount())
			{
			case 0: ExecuteAction(id); break;
			case 1: ExecuteAction(id, arg1); break;
			case 2: ExecuteAction(id, arg1, arg2); break;
			case 3: ExecuteAction(id, arg1, arg2, arg3); break;
			case 4: ExecuteAction(id, arg1, arg2, arg3, arg4); break;
			case 5: ExecuteAction(id, arg1, arg2, arg3, arg4, arg5); break;
			}
		}
		template<typename R>
		inline R DispatcherBase<R>::ExecuteAction(int id)
		{
			return ExecuteAction(id, 0, 0, 0, 0, 0);
		}
		template<typename R>
		inline R DispatcherBase<R>::ExecuteAction(int id, uint8_t arg1)
		{
			return ExecuteAction(id, arg1, 0, 0, 0, 0);
		}
		template<typename R>
		inline R DispatcherBase<R>::ExecuteAction(int id, uint8_t arg1, uint8_t arg2)
		{
			return ExecuteAction(id, arg1, arg2, 0, 0, 0);
		}
		template<typename R>
		inline R DispatcherBase<R>::ExecuteAction(int id, uint8_t arg1, uint8_t arg2, uint8_t arg3)
		{
			return ExecuteAction(id, arg1, arg2, arg3, 0, 0);
		}
		template<typename R>
		inline R DispatcherBase<R>::ExecuteAction(int id, uint8_t arg1, uint8_t arg2, uint8_t arg3, uint8_t arg4)
		{
			return ExecuteAction(id, arg1, arg2, arg3, arg4, 0);
		}
		template<typename R>
		inline R DispatcherBase<R>::ExecuteAction(int id, uint8_t arg1, uint8_t arg2, uint8_t arg3, uint8_t arg4, uint8_t arg5)
		{
			return this->containers[id]->CallAction(arg1, arg2, arg3, arg4, arg5);
		}
	}
}