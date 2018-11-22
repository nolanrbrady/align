[%bs.raw {|require('./app.css')|}];

[@bs.module] external logo : string = "./logo.svg";

type page = 
  | Dashboard
  | Users;

type state = { route: page }

type action =
  | UpdatePage(page);

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {
    route: Dashboard
  },
  
  reducer: (action, _state) =>
  switch (action) {
  | UpdatePage(route) => ReasonReact.Update({ route: route });
  },

  render: ({ state }) =>
    <div className="App">
     (
       switch (state.route){
       | Dashboard => <Dashboard />
       | Users => <Users />
       }
     )
    </div>,
};
