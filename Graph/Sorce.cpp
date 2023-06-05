#include <iostream>
#include "Graph.h"
#include <SFML/Graphics.hpp>
#include "Vert.h"
#include "Btn.h"
#include "TxtMess.h"
#include "Func.h"
#include "Edge.h"
using namespace sf;
using namespace std;

const Color WindowColor = Color(255, 255, 255);
const int StartX = 60;
const int StartY = 60;

int main()
{
	setlocale(0, "ru");
	Graph<int> gr;

	RenderWindow Window(VideoMode(800, 600), L"Граф");
	Window.setVerticalSyncEnabled(true);
	int vi = 1;

	Button AddVertexBtn("Добавить вершину", Window.getSize(), 50);
	Button AddEdgeBtn("Добавить ребро", Window.getSize(), 100);
	Button DelBtn("Удалить", Window.getSize(), 150);

	Button SalesmanBtn("Коммивояжер", Window.getSize(), 1200);

	Button ApplyBtn("Подтвердить", Window.getSize(), 300);

	vector<Vert*> VertexDrawingQueue;
	vector<EdgeL*> EdgeDrawingQueue;
	Vert* movingVert = nullptr;
	vector<EdgeL*> movingEdges;
	Vert* AddedVertex = nullptr;
	EdgeL* AddedEdge = nullptr;

	TextMessage BMessage(Window, "");

	vector<Vert*> TmpVertexes;
	vector<EdgeL*> TmpEdges;

	bool AnyBtnOn = false;
	bool MustShowApply = false;

	Vector2i prev_mousePos;

	while (Window.isOpen())
	{
		Vector2i mousePos = Mouse::getPosition(Window);
		Vector2u prevsize = Window.getSize();
		Vector2i prevWpos = Window.getPosition();

		Window.clear(WindowColor);
		DrawEdges(Window, EdgeDrawingQueue);
		DrawButtons(Window, 4, AddVertexBtn, AddEdgeBtn, DelBtn, SalesmanBtn);
		DrawButtons(Window, 4, AddVertexBtn, AddEdgeBtn, DelBtn);
		if (MustShowApply) Window.draw(ApplyBtn);
		DrawVertexes(Window, VertexDrawingQueue);
		Window.draw(BMessage);
		Window.display();
		
		SetCursor(Window, mousePos, VertexDrawingQueue, EdgeDrawingQueue, AddVertexBtn, AddEdgeBtn, DelBtn, ApplyBtn, SalesmanBtn, MustShowApply);

		Event event;
		while (Window.pollEvent(event))
		{
			switch (event.type)
			{

			case Event::Closed:
				Window.close();
				break;

			case Event::MouseButtonPressed:
				if (event.mouseButton.button == Mouse::Left)
				{
					if (AddVertexBtn.contain(mousePos) && not_intersection(VertexDrawingQueue, mousePos))
					{
						if (AnyBtnOn)
						{
							CheckVertecies(TmpVertexes);
							CheckEdges(TmpEdges);
							SalesmanBtn.setMode(Off);
							DelBtn.setMode(Off);
							AddEdgeBtn.setMode(Off);
						}
						AddVertexBtn.setMode(On);

						BMessage.set_string(Window, "");
						AddedVertex = new Vert(to_string(vi));
						AddedVertex->set_position(StartX, StartY);
						AddedVertex->set_color(VertexHighlightedColor);
					    VertexDrawingQueue.push_back(AddedVertex);
					    gr.add_vertex(to_string(vi));
					    vi++;
					}

					if (AddEdgeBtn.contain(mousePos) && not_intersection(VertexDrawingQueue, mousePos))
					{
						if (AddEdgeBtn.Mode() == On)
						{
							if (VertexDrawingQueue.size() > 0) BMessage.set_string(Window, "");
							else BMessage.set_string(Window, "");
							AddEdgeBtn.setMode(Off);
							CheckVertecies(TmpVertexes);
							CheckEdges(TmpEdges);
							AnyBtnOn = false;
						}
						else if (AddEdgeBtn.Mode() == Off)
						{
							if (AnyBtnOn)
							{
								CheckVertecies(TmpVertexes);
								CheckEdges(TmpEdges);
								DelBtn.setMode(Off);
								SalesmanBtn.setMode(Off);
							}
							BMessage.set_string(Window, "");
							AddEdgeBtn.setMode(On);
							AnyBtnOn = true;
						}
					}
					else if (AddEdgeBtn.Mode() == On)
					{
						bool Continue = true;
						for (int i = VertexDrawingQueue.size() - 1; i >= 0 && Continue; i--)
						{
							if (VertexDrawingQueue[i]->contain(mousePos))
							{
								if (VertexDrawingQueue[i]->get_color() == VertexDefaultColor)
								{
									if (TmpVertexes.size() < 2)
									{
										VertexDrawingQueue[i]->set_color(VertexHighlightedColor);
										TmpVertexes.push_back(VertexDrawingQueue[i]);
									}
								}
								else
								{
									VertexDrawingQueue[i]->set_color(VertexDefaultColor);

									vector<Vert*>::iterator it = TmpVertexes.begin();
									for (it; it != TmpVertexes.end() && *it != VertexDrawingQueue[i]; it++) {}
									TmpVertexes.erase(it);
								}
								Continue = false;
							}
						}
						MustShowApply = TmpVertexes.size() == 2;
					}

					if (DelBtn.contain(mousePos) && not_intersection(VertexDrawingQueue, mousePos))
					{
						if (DelBtn.Mode() == On)
						{
							if (VertexDrawingQueue.size() > 0) BMessage.set_string(Window, "");
							else BMessage.set_string(Window, "");
							DelBtn.setMode(Off);
							CheckVertecies(TmpVertexes);
							CheckEdges(TmpEdges);
							AnyBtnOn = false;
						}
						else if (DelBtn.Mode() == Off)
						{
							if (AnyBtnOn)
							{
								CheckVertecies(TmpVertexes);
								CheckEdges(TmpEdges);
								AddEdgeBtn.setMode(Off);
								SalesmanBtn.setMode(Off);
							}
							BMessage.set_string(Window, "");
							DelBtn.setMode(On);
							AnyBtnOn = true;
						}
					}
					else if (DelBtn.Mode() == On)
					{
						bool Continue = true;
						for (int i = VertexDrawingQueue.size() - 1; i >= 0 && Continue; i--)
						{
							if (VertexDrawingQueue[i]->contain(mousePos))
							{
								if (VertexDrawingQueue[i]->get_color() == VertexDefaultColor)
								{
									VertexDrawingQueue[i]->set_color(VertexHighlightedColor);
									TmpVertexes.push_back(VertexDrawingQueue[i]);
									for (int j = 0; j < EdgeDrawingQueue.size(); j++)
									{
										if (EdgeDrawingQueue[j]->containVert(VertexDrawingQueue[i]) && EdgeDrawingQueue[j]->get_color() == EdgeDefaultColor)
										{
											EdgeDrawingQueue[j]->set_color(EdgeHighlightedColor);
											TmpEdges.push_back(EdgeDrawingQueue[j]);
										}
									}
								}
								else
								{
									VertexDrawingQueue[i]->set_color(VertexDefaultColor);
									vector<Vert*>::iterator it = TmpVertexes.begin();
									for (it; it != TmpVertexes.end() && *it != VertexDrawingQueue[i]; it++) {}
									TmpVertexes.erase(it);
									for (int j = 0; j < TmpEdges.size(); j++)
									{
										if (TmpEdges[j]->get_start() == VertexDrawingQueue[i])
										{
											if (TmpEdges[j]->get_end()->get_color() == VertexDefaultColor)
											{
												TmpEdges[j]->set_color(EdgeDefaultColor);
												vector<EdgeL*>::iterator it = TmpEdges.begin() + j;
												TmpEdges.erase(it);
												--j;
											}
										}
										else if (TmpEdges[j]->get_end() == VertexDrawingQueue[i])
										{
											if (TmpEdges[j]->get_start()->get_color() == VertexDefaultColor)
											{
												TmpEdges[j]->set_color(EdgeDefaultColor);
												vector<EdgeL*>::iterator it = TmpEdges.begin() + j;
												TmpEdges.erase(it);
												--j;
											}
										}
									}
								}
								Continue = false;
							}
						}

						for (int i = EdgeDrawingQueue.size() - 1; i >= 0 && Continue; i--)
						{
							if (EdgeDrawingQueue[i]->contain(mousePos))
							{
								if (EdgeDrawingQueue[i]->get_color() == EdgeDefaultColor)
								{
									for (int j = 0; j < TmpVertexes.size(); j++)
									{
										if (TmpVertexes[j] == EdgeDrawingQueue[i]->get_start() || TmpVertexes[j] == EdgeDrawingQueue[i]->get_end())
										{
											Continue = false;
										}
									}
									if (Continue)
									{
										EdgeDrawingQueue[i]->set_color(EdgeHighlightedColor);
										TmpEdges.push_back(EdgeDrawingQueue[i]);
									}
								}
								else
								{
									for (int j = 0; j < TmpVertexes.size(); j++)
									{
										if (!EdgeDrawingQueue[i]->containVert(TmpVertexes[j]))
										{
											EdgeDrawingQueue[i]->set_color(EdgeDefaultColor);
											vector<EdgeL*>::iterator it = TmpEdges.begin();
											for (it; it != TmpEdges.end() && *it != EdgeDrawingQueue[i]; it++) {}
											TmpEdges.erase(it);
										}
									}
								}
								Continue = false;
							}
						}

						MustShowApply = TmpVertexes.size() > 0 || TmpEdges.size() > 0;
					}

					if (ApplyBtn.contain(mousePos) && not_intersection(VertexDrawingQueue, mousePos))
					{
						ApplyBtn.setMode(On);

						if (DelBtn.Mode() == On)
						{
							for (int i = 0; i < TmpEdges.size(); i++)
							{
								vector<EdgeL*>::iterator del;

								del = EdgeDrawingQueue.begin();
								for (del; del != EdgeDrawingQueue.end() && (*del != TmpEdges[i]); del++) {}
								gr.delete_edge(TmpEdges[i]->get_start()->getText(), TmpEdges[i]->get_end()->getText());
								if (gr.is_edge(TmpEdges[i]->get_end()->getText(), TmpEdges[i]->get_start()->getText()))
								{
									int j = 0;
									while (j < EdgeDrawingQueue.size() && (EdgeDrawingQueue[j]->get_start() != TmpEdges[i]->get_end() || EdgeDrawingQueue[j]->get_end() != TmpEdges[i]->get_start()))
									{
										j++;
									}
									EdgeDrawingQueue[j]->setAnotherEdge(false);
								}
								EdgeDrawingQueue.erase(del);
								delete TmpEdges[i];
								TmpEdges[i] = nullptr;
							}
							TmpEdges.clear();

							for (int i = 0; i < TmpVertexes.size(); i++)
							{
								vector<Vert*>::iterator del;

								del = VertexDrawingQueue.begin();
								for (del; del != VertexDrawingQueue.end() && (*del != TmpVertexes[i]); del++) {}
								VertexDrawingQueue.erase(del);

								gr.delete_vertex(TmpVertexes[i]->getText());

								delete TmpVertexes[i];
								TmpVertexes[i] = nullptr;
							}
							TmpVertexes.clear();
						}
						else if (AddEdgeBtn.Mode() == On)
						{
							switch (VertexDrawingQueue.size())
							{
							case 2:
								if (EdgeDrawingQueue.size() <= 1)
								{
									if (!gr.is_edge(TmpVertexes[0]->getText(), TmpVertexes[1]->getText()))
									{
										bool AnotherEdge = gr.is_edge(TmpVertexes[1]->getText(), TmpVertexes[0]->getText());
										AddedEdge = new EdgeL(TmpVertexes[0], TmpVertexes[1], AnotherEdge);
										AddedEdge->set_color(EdgeHighlightedColor);
										EdgeDrawingQueue.push_back(AddedEdge);
										gr.add_edge(TmpVertexes[0]->getText(), TmpVertexes[1]->getText(), 0, true);
										if (AnotherEdge)
										{
											int i = 0;
											while (i < EdgeDrawingQueue.size() && (EdgeDrawingQueue[i]->get_start() != TmpVertexes[1] || EdgeDrawingQueue[i]->get_end() != TmpVertexes[0]))
											{
												i++;
											}
											EdgeDrawingQueue[i]->setAnotherEdge(AnotherEdge);
										}
									}
									else
									{
										BMessage.set_string(Window, "There is already an edge between this vertices.");
									}
								}
								else
								{
									BMessage.set_string(Window, "Graph is already full.");
								}
								break;
							default:
								if (EdgeDrawingQueue.size() < VertexDrawingQueue.size() * (VertexDrawingQueue.size() - 3) + VertexDrawingQueue.size() * 2)
								{
									if (!gr.is_edge(TmpVertexes[0]->getText(), TmpVertexes[1]->getText()))
									{
										bool AnotherEdge = gr.is_edge(TmpVertexes[1]->getText(), TmpVertexes[0]->getText());
										AddedEdge = new EdgeL(TmpVertexes[0], TmpVertexes[1], AnotherEdge);
										AddedEdge->set_color(EdgeHighlightedColor);
										EdgeDrawingQueue.push_back(AddedEdge);
										gr.add_edge(TmpVertexes[0]->getText(), TmpVertexes[1]->getText(), 0, true);
										if (AnotherEdge)
										{
											int i = 0;
											while (i < EdgeDrawingQueue.size() && (EdgeDrawingQueue[i]->get_start() != TmpVertexes[1] || EdgeDrawingQueue[i]->get_end() != TmpVertexes[0]))
											{
												i++;
											}
											EdgeDrawingQueue[i]->setAnotherEdge(AnotherEdge);
										}
									}
									else
									{
										BMessage.set_string(Window, "There is already an edge between this vertices.");
									}
								}
								else
								{
									BMessage.set_string(Window, "Graph is already full.");
								}
								break;
							}

						}
					}

					if (SalesmanBtn.contain(mousePos) && not_intersection(VertexDrawingQueue, mousePos))
					{
						if (SalesmanBtn.Mode() == On)
						{
							if (VertexDrawingQueue.size() > 0) BMessage.set_string(Window, "");
							else BMessage.set_string(Window, "");
							SalesmanBtn.setMode(Off);
							CheckVertecies(TmpVertexes);
							CheckEdges(TmpEdges);
							AnyBtnOn = false;
						}
						else if (SalesmanBtn.Mode() == Off)
						{
							if (AnyBtnOn)
							{
								DelBtn.setMode(Off);
								AddEdgeBtn.setMode(Off);
								CheckVertecies(TmpVertexes);
								CheckEdges(TmpEdges);
							}
							BMessage.set_string(Window, "");
							SalesmanBtn.setMode(On);
							AnyBtnOn = true;
						}
					}
					else if (SalesmanBtn.Mode() == On)
					{
						for (int i = 0; i < VertexDrawingQueue.size(); i++)
						{
							if (VertexDrawingQueue[i]->contain(mousePos))
							{
								if (VertexDrawingQueue[i]->get_color() == VertexDefaultColor)
								{
									if (TmpVertexes.size() == 0)
									{
										VertexDrawingQueue[i]->set_color(VertexHighlightedColor);
										TmpVertexes.push_back(VertexDrawingQueue[i]);
										if (gr.is_weighted())
										{
											vector<GraphVertex<int>*> vroute = gr.Salesman(VertexDrawingQueue[i]->getText());
											if (vroute.size() == VertexDrawingQueue.size() + 1)
											{
												string sroute = gr.get_str_route(vroute);
												BMessage.set_string(Window, sroute);
											}
											else
											{
												BMessage.set_string(Window, "There's no way for Salesman.");
											}
										}
										else
										{
											BMessage.set_string(Window, "Not all edges have weight.");
										}
									}
								}
								else if (VertexDrawingQueue[i]->get_color() == VertexHighlightedColor)
								{
									if (TmpVertexes.size() == 1)
									{
										VertexDrawingQueue[i]->set_color(VertexDefaultColor);
										TmpVertexes.erase(vector<Vert*>::iterator(TmpVertexes.begin()));
										BMessage.set_string(Window, "");
									}
								}
							}
						}
					}

					if (!AnyBtnOn)
					{
						bool Continue = true;
						for (int i = VertexDrawingQueue.size() - 1; i >= 0 && Continue; i--)
						{
							if (VertexDrawingQueue[i]->contain(mousePos))
							{
								movingVert = VertexDrawingQueue[i];
								movingVert->set_color(VertexHighlightedColor);
								vector<Vert*>::iterator it = VertexDrawingQueue.begin();
								for (it; it != VertexDrawingQueue.end() && *it != movingVert; it++) {}
								VertexDrawingQueue.erase(it);
								VertexDrawingQueue.push_back(movingVert);

								for (int i = 0; i < EdgeDrawingQueue.size(); i++)
								{
									if (EdgeDrawingQueue[i]->containVert(movingVert))
									{
										movingEdges.push_back(EdgeDrawingQueue[i]);
									}
								}
								Continue = false;
							}
						}
					}
				}

				else if (event.mouseButton.button == Mouse::Right)
				{
					bool Continue = true;

					for (int i = VertexDrawingQueue.size() - 1; i >= 0 && Continue; i--)
					{
						if (VertexDrawingQueue[i]->contain(mousePos))
						{
							if (AnyBtnOn)
							{
								CheckVertecies(TmpVertexes);
								CheckEdges(TmpEdges);
								SalesmanBtn.setMode(Off);
								AddEdgeBtn.setMode(Off);
								DelBtn.setMode(Off);
								AnyBtnOn = false;
							}
							Window.clear(WindowColor);

							DrawEdges(Window, EdgeDrawingQueue);
							BMessage.set_string(Window, "");
							DrawButtons(Window, 4, AddVertexBtn, AddEdgeBtn, DelBtn, SalesmanBtn);
							VertexDrawingQueue[i]->set_color(VertexHighlightedColor);
							TmpVertexes.push_back(VertexDrawingQueue[i]);
							vector<Vert*>::iterator it = VertexDrawingQueue.begin() + i;
							VertexDrawingQueue.erase(it);
							VertexDrawingQueue.push_back(TmpVertexes[0]);
							DrawVertexes(Window, VertexDrawingQueue);
							Window.display();

							VertexSettingsWindow(TmpVertexes[0], EdgeDrawingQueue, gr);
							
							Continue = false;
							TmpVertexes[0]->set_color(VertexDefaultColor);
							TmpVertexes.clear();
						}
					}

					for (int i = 0; i < EdgeDrawingQueue.size() && Continue; i++)
					{
						if (EdgeDrawingQueue[i]->contain(mousePos))
						{
							if (AnyBtnOn)
							{
								CheckVertecies(TmpVertexes);
								CheckEdges(TmpEdges);
								SalesmanBtn.setMode(Off);
								AddEdgeBtn.setMode(Off);
								DelBtn.setMode(Off);
								AnyBtnOn = false;
							}

							EdgeDrawingQueue[i]->set_color(EdgeHighlightedColor);

							Window.clear(WindowColor);

							BMessage.set_string(Window, "");
							DrawEdges(Window, EdgeDrawingQueue);
							DrawButtons(Window, 4, AddVertexBtn, AddEdgeBtn, DelBtn, SalesmanBtn);
							DrawVertexes(Window, VertexDrawingQueue);

							Window.display();

							EdgeSettingsWindow(EdgeDrawingQueue[i], gr, EdgeDrawingQueue);

							Continue = false;
							if (EdgeDrawingQueue[i] != nullptr) EdgeDrawingQueue[i]->set_color(EdgeDefaultColor);
							else
							{
								vector<EdgeL*>::iterator del;
								del = EdgeDrawingQueue.begin() + i;
								EdgeDrawingQueue.erase(del);
							}
						}
					}
				}
				break;

			case Event::MouseMoved:
				if (movingVert != nullptr)
				{
					MoveVertex(Window, movingVert, movingEdges, mousePos, prev_mousePos);
				}
				break;

			case Event::MouseButtonReleased:
				if (movingVert != nullptr)
				{
					movingVert->set_color(VertexDefaultColor);
					movingVert = nullptr;
					movingEdges.clear();
				}

				if (AddVertexBtn.Mode() == On)
				{
					AddVertexBtn.setMode(Off);
					AddedVertex->set_color(VertexDefaultColor);
					AddedVertex = nullptr;
					AnyBtnOn = false;
				}
				else if (AddEdgeBtn.Mode() == On && ApplyBtn.Mode() == On)
				{
					VertexesDefaultColor(TmpVertexes);
					if (AddedEdge != nullptr)
					{
						AddedEdge->set_color(EdgeDefaultColor);
						AddedEdge = nullptr;
					}
					TmpVertexes.clear();
				}

				ApplyBtn.setMode(Off);
				if (TmpVertexes.size() == 0 && TmpEdges.size() == 0) MustShowApply = false;
				break;

			case Event::KeyPressed:
				if (event.key.code == Keyboard::Escape)
				{
					if (VertexDrawingQueue.size() > 0) BMessage.set_string(Window, "");
					else BMessage.set_string(Window, "");

					if (AnyBtnOn)
					{
						AddEdgeBtn.setMode(Off);
						DelBtn.setMode(Off);
						SalesmanBtn.setMode(Off);
						CheckVertecies(TmpVertexes);
						CheckEdges(TmpEdges);
						AnyBtnOn = false;
					}
					
					else Window.close();
				}
				break;

			case Event::Resized: 
				SetResize(Window, prevWpos, prevsize, AddVertexBtn, AddEdgeBtn, DelBtn, ApplyBtn, SalesmanBtn, BMessage, VertexDrawingQueue, EdgeDrawingQueue);
				break;
			}
		}
		prev_mousePos = mousePos;
	}

	for (int i = 0; i < VertexDrawingQueue.size(); i++)
	{
		delete VertexDrawingQueue[i];
	}

	for (int i = 0; i < EdgeDrawingQueue.size(); i++)
	{
		delete EdgeDrawingQueue[i];
	}
	gr.print_matrix();
	cout << "Обход в глубину:" << endl;
	gr.depth_first_search("1");
	cout << endl;
	cout << "Обход в ширину:" << endl;
	gr.breadth_first_search("1");
	cout << endl;
	VertexDrawingQueue.clear();
	EdgeDrawingQueue.clear();
	cout << "Алгоритм Дейкстры:" << endl;
	gr.Dijkstra("1");

	return 0;
}