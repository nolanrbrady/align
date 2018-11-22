
let component = ReasonReact.statelessComponent("App");

let make = (_children) => {
  ...component,
  render: _self =>
    <div className="App">
      <h1>(ReasonReact.string("Welcome to the Dashboard"))</h1>
    </div>,
};
