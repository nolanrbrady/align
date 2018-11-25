
type item = {
    name: string,
    completed: bool,
}

type action = 
  | Increment
  | Decrement
  | AddItem(item);

type state = {
    count: int,
    items: list(item)
}

let str = ReasonReact.string;

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,

  /* Initial State */
  initialState:() => {
    count: 0,
    items: [{ name: "Test Item", completed: false }, { name: "Another Test Item", completed:false }]
},

    /* Reducer */
    reducer: (action, state) => 
        switch (action) {
        | AddItem(item) => ReasonReact.Update({ ...state, items: [item, ...state.items] })
        | Increment => ReasonReact.Update({...state, count: state.count + 1 })
        | Decrement => ReasonReact.Update({...state, count: state.count - 1 })
    },

  render: ({state, send}) =>
    <div className="App">
      <h1>(ReasonReact.string("Rendering from Local State"))</h1>
      <p>(str(string_of_int(state.count)))</p>
      <div>
        <h4 onClick=((_e) => send(Increment))>(str("Increment Count"))</h4>
        <h4 onClick=((_e) => send(Decrement))>(str("Decrement Count"))</h4>
      </div>
      <h1>(str("Rendering from Global State"))</h1>
    </div>,
};
